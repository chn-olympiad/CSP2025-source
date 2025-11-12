#include <bits/stdc++.h>
using namespace std;
const int mn = 110;
int n, m;
struct student {
    int a;
    int id;
};
vector<student> students(mn);
int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int total = n * m;
    for (int i = 1; i <= total; i++) {
        cin >> students[i].a;
        students[i].id = i;
    }
    sort(students.begin() + 1, students.begin() + 1 + total, [](student a, student b) {
        return a.a > b.a;
    });
    for (int i = 1; i <= total; i++) {
        int r = ((i - 1) / n) + 1;
        int c = ((i - 1) % n) + 1;
        if (r % 2 == 0) {
            c = n - c + 1;
        }
        if (students[i].id == 1) {
            cout << r << " " << c << "\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}