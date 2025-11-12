#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 15
#define M 15
using namespace std;

bool flag = false;

int __count = 0;
int n, m, real_score;
int scores[N * M + 2];

void judge() {
    if (scores[__count] == real_score)
        flag = true;

    __count++;
}

bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;
    int counts = n * m;

    for (int i = 0; i < counts; i++)
        cin >> scores[i];

    real_score = scores[0];
    sort(scores, scores + counts, cmp);

    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            for (int j = 1; j <= m; j++) {
                judge();
                if (flag) {
                    cout << i << " " << j << endl;
                    break;
                }
            }
        }
        else {
            for (int j = m; j >= 1; j--) {
                judge();
                if (flag) {
                    cout << i << " " << j << endl;
                    break;
                }
            }
        }

        if (flag) break;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}