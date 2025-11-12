#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[15][15];
int pos,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[j][i];
        }
    }
    for (int x = 1; x <= 1e9; x++){
        for (int i = 1; i <= m; i++){
            for (int j = 2 j <= n; j++){
                if (a[j][i]>a[j-1][i]){
                    int t = a[j][i];
                    a[j][i]=a[j-1][i];
                    a[j-1][i]=t;
                    pos++;
                }
            }
        }
        if (!pos){
            break;
        }
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
        cnt++;
            if (a[j][i]==a[1][1]){
                cout << cnt;
            }
        }
    }
    return 0;
}
