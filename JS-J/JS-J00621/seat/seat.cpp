#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 15;
const int MAXS = MAXN * MAXN;
int arr[MAXS], n, m, r;
bool cmp(int first, int second) {
    return first > second;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> arr[i];
        if (i == 1) {
            r = arr[i];
        }
    }
    sort(arr + 1, arr + n * m + 1, cmp);
    int ptr = 1;
    for (int j = 1; j <= m; j++) {
        if (j % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                if (arr[ptr] == r) {
                    cout << j << " " << i;
                    return 0;
                }
                ptr++;
            }
        }
        else {
            for (int i = n; i >= 1; i--) {
                if (arr[ptr] == r) {
                    cout << j << " " << i;
                    return 0;
                }
                ptr++;
            }
        }
    }
    return 0;
}

