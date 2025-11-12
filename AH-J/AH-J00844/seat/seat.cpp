#include <bits/stdc++.h>
using namespace std;

const int N = 19;
int a[N * N];
int s[N][N];

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    int tot = n * m;
    for (int i = 1; i <= tot; i++) cin >> a[i];
    int r = a[1];

    sort(a + 1, a + tot + 1, greater<int>());

    int num = 1;
    for (int j = 1; j <= m; j++){
        if (j % 2 == 1){
            for (int i = 1; i <= n; i++){
                s[i][j] = num++;
            }
        }
        else if (j % 2 == 0){
            for (int i = n; i >= 1; i--){
                s[i][j] = num++;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int cur = a[s[i][j]];
            if (cur == r){
                cout << j << ' ' << i << '\n';
                return 0;
            }
            // cout << s[i][j] << ' ';
        }
        // cout << '\n';
    }
    return 0;
}