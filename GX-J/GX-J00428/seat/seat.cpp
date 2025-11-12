#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    int a[n * m];
    for(int i = 0; i < n * m; i++) {
        cin >> a[i];
    }

    int r = a[0];
    sort(a, a + n * m);

    int arr[n][m];
    int f = 1;
    int k = n * m - 1;
    for(int i = 0; i < n;) {
        for(int j = 0; j < m;) {
            if(a[k] == r) {
                cout << j + 1 << " " << i + 1 << endl;
                return 0;
            }

            arr[i][j] = a[k];
            k--;

            if(i == 0 && j < m - 1 && j) {
                j++;
                f = 1;
                continue;
            }
            else if(i == n - 1 && j < m - 1) {
                j++;
                f = -1;
                continue;
            }

            i += f;
        }
    }


    return 0;
}
