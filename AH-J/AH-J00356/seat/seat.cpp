#include <bits/stdc++.h>
using namespace std;
#define int long long
int s[15][15],b[105],c[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,f = 0;
    cin >> n >> m;
    for (int i = 1;i <= n * m;i++){
        cin >> b[i];
    }
    int a1 = b[1];
    for (int i = 100;i >= 1;i--){
        for (int j = 1;j <= n*m;j++){
            if (b[j] == i) {
                f++;
                c[f] = b[j];
            }
        }
    }
    f = 0;
    for (int i = 1;i <= n;i++){
        if (i % 2 == 1){
            for (int j = 1;j <= m;j++){
                f++;
                s[i][j] = c[f];
            }
        }
        else {
            for (int j = m;j >= 1;j--){
                f++;
                s[i][j] = c[f];
            }
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (a1 == s[j][i]) {
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
