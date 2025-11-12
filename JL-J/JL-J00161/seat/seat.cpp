#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 105;

struct Student {
    int score, id;

    friend bool operator < (Student a, Student b) {
        return a.score > b.score;
    }
};

int n, m;
Student stu[N];

void inp() {
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n * m; i ++ ) {
        scanf("%d", &stu[i].score);
        stu[i].id = i;
    }
}

void work() {
    sort(stu + 1, stu + n * m + 1);
    int x = 1, y = 1;
    int base = 1;

    for(int i = 1; i <= n * m; i ++ ) {
        if (stu[i].id == 1) {
            printf("%d %d\n", y, x);
            return;
        }

        x += base;

        if (x < 1 || x > n) {
            x -= base;
            y ++ ;
            base = -base;
        }
    }
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    inp();
    work();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
