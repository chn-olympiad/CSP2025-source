#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 1;
int n, m;
int arr[N];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++) {
        cin >> arr[i];
    }
    int cj = arr[1];
    sort(arr + 1, arr + 1 + n * m, cmp);

    int c = 1, r = 1, flag = 1;//c -> y\r -> x
    for (int i = 1; i <= n * m; i++) {
        if (arr[i] == cj) {
            cout << c << " " << r;
            return 0;
        }
        if (r == 1 && flag == -1) {
            c++;
            flag = 1;
        } else if (r == n && flag == 1) {
            c++;
            flag = -1;
        } else {
            r += flag;
        }
    }
    return 0;
}
