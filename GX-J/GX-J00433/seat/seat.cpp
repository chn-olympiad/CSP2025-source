#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n, m, x;
    cin >> n >> m;
    int a[n+1][m+1];

    for (int i=1; i<=m; i++){
            if (i%2!=0){
                for (int j=1; j<=n; j++){
                    cin >> a[i][j];
                    f=a[1][1];
                }
                for (int j=2; j<=n; j++){
                    if (a[i][j-1]<a[i][j]){
                        x=a[i][j-1];
                        a[i][j-1] = a[i][j];
                        a[i][j]=x;
                    }
                }
            }
            else{
                for (int j=n; j>=1; j--){
                    cin >> a[i][j];
                }
                for (int j=n-1; j>=1; j--){
                    if (a[i][j+1]<a[i][j]){
                        x=a[i][j+1];
                        a[i][j+1] = a[i][j];
                        a[i][j]=x;
                    }
                }
            }

        }
        for (int i=1; i<=m; i++){
            if (i%2!=0){
                for (int j=1; j<=n; j++){
                    if (a[i][j]==f){
                        cout << i << " " << j;
                        return 0;
                    }
                }
            }
            else{
                for (int j=n; j>=1; j--){
                    if (a[i][j]==f){
                        cout << i << " " << j;
                        return 0;
                    }
                }
            }

        }
    return 0;
}

