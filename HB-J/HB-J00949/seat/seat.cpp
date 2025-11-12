#include<bits/stdc++.h>
using namespace std;
int a[111][111];
int b[111111];
int n, m, bi;
int main (){
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n*m; ++i){
        cin >> b[i];
    }
    int ans = b[1], ansi, ansj;

    for (int i = n*m; i >= 2; --i){
        for (int j = i-1; j >= 1; --j){
            if (b[i] < b[j]){
                swap (b[i], b[j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        if (i%2){
            for (int j = 1; j <= m; ++j){
                a[j][i] = b[++bi];
            }
        }else{
            for (int j = m; j >= 1; --j){
                a[j][i] = b[++bi];
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == ans){
                ansi = i;
                ansj = j;
            }
        }
    }
    cout << ansi << " " << ansj;


    return 0;
}
