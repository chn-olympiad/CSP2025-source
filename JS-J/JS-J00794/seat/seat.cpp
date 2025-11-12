#include<bits/stdc++.h>
using namespace std;//100
const int N = 109;
int a[N][N];
int b[N << 1];
int n, m;
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) cin >> b[i];
    int x = b[1];
    sort(b + 1, b + n * m + 1, greater<int>());
    int tot = 0;
    for(int j = 1; j <= m; j += 2){
        for(int i = 1; i <= n; i++) a[i][j] = b[++tot];
        for(int i = n; i >= 1; i--) a[i][j + 1] = b[++tot];
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] == x){
                cout << j << " " << i;
                return 0;
            }
    return 0;
}
