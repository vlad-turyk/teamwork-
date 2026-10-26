#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

//  Функція 1: додавання завдання (Учасник 1)
void addTask(vector<string>& tasks, const string& title) {
    tasks.push_back(title);
    cout << "Додано: " << title << endl;
}
//  Функція 2: видалення завдання (Учасник 2)
void removeTask(vector<string>& tasks, int index) {
    if (index >= 0 && index < (int)tasks.size()) {
        cout << "Видалено: " << tasks[index] << endl;
        tasks.erase(tasks.begin() + index);
    } else {
        cout << "Невірний номер" << endl;
    }
}

//  Функція 3: відображення списку (Учасник 2) 
void showTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Список порожній" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i << ". " << tasks[i] << endl;
    }
}
int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    vector<string> tasks;
    string cmd;

    while (true) {
        cout << "add / remove / show / exit: ";
        cin >> cmd;

        if (cmd == "add") {
            string title;
            cout << "Завдання: ";
            cin.ignore();
            getline(cin, title);
            addTask(tasks, title);
        } else if (cmd == "remove") {
            int index;
            cout << "Номер: ";
            cin >> index;
            removeTask(tasks, index);
        } else if (cmd == "show") {
            showTasks(tasks);
        } else if (cmd == "exit") {
            break;
        }
    }
    return 0;
}