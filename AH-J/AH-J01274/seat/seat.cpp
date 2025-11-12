#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    int arr[n*m];

    cin >> n >> m;
    for (int i = 0; i <n *m i++) {
        cin >> arr[i];
    }

    int top = arr[0];

    sort(arr, arr + n*m, [](int b, int c){
        return b > c;
    });

    int result[n+1][m+1], n_ = 0;
    bool is_break=false;

    for (int b = 1; b <= m; b++) {
        for (int a = (b%2 ? n : 1); a > (n%2 ? 0 :n ); a--) {
            result[a][b] = arr[n_];
            if (result[a][b] == top) {
                cout << b << a << endl;
                is_break = true;
                break;
            }
            n_++;
        }
        if (is_break) break;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
