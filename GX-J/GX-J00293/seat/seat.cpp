#include <bits/stdc++.h>
using namespace std;
int n,m,u,sum;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    int a[n][m];
    int f = n * m;
    int b[f];
    for (int i = 1;i <= f;i++){
            cin >> b[i];
            if (i == 1){
                sum = b[i];
            }
    }
    sort(b+1,b+1+f);
    reverse(b+1,b+1+f);
    int q = 1;
    for (int i = 1;i <= m;i++){
        if (i % 2 == 1){
            for (int j = 1;j <= n;j++){
                a[i][j] = b[q];
                q++;
            }
        }
        else{
            for (int j = n;j >= 1;j--){
                a[i][j] = b[q];
                q++;
            }
        }
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (a[i][j] == sum){
                cout << i << " " << j;
            }
        }
    }
    cout << "\n";
    return 0;
}
