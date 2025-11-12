#include<bits/stdc++.h>
using namespace std;
int n, m, a[1005], r, b[39][39];
int cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n * m; i++){
        cin >> a[i];
    }
    r = a[1];
    sort(a + 1, a + n * m + 1, cmp);
    int i = 1, j = 1, k = 1;
    while(j <= m){
        if (i == 1){
            while (i <= n){
                b[i][j] = a[k++];
                i++;
            }
        }
        else if (i == 0){
            i++;
            while (i <= n){
                b[i][j] = a[k++];
                i++;
            }
        }
        else if (i == n + 1){
            i--;
            while (i >= 1){
                b[i][j] = a[k++];
                i--;
            }
        }
        j++;
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (b[i][j] == r){
                cout << j << " " << i;
                break;
            }
        }
    }
    return 0;
}








































