#include <bits/stdc++.h>
using namespace std;
int main(){

    long long a[105][105];
    int n,m,c,r,b[101];
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            cin >> a[i][j];
        }
    }

    for(int i = 1;i<=n*m;i++){

        b[i]= a[n][m];

    }
    sort(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        for(int j= 1;j<=m;j++){
            if(a[n][m]==b[1]){
            cout << a[n][m];
            }
        }
    }
    return 0;
}
