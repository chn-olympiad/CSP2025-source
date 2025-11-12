#include <bits/stdc++.h>
using namespace std;
int tj[15][15] = {0};
bool cmp(int a, int b){
    return a>b;
}
int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m, a[105];
    cin >> n >> m;
    for (int i=1; i<=n*m; i++){
        cin >> a[i];
    }
    int s=a[1], l=n*m;
    sort(a+1, a+l+1, cmp);
    int ts=1, i=1, j=1;
    while (true){
        tj[i][j] = a[ts];
        ts++;
        if (j%2==1){
            if (i != n)
                i++;
            else
                j++;
        }
        else{
            if (i != 1)
                i--;
            else
                j++;
        }
        if ((i == 1 && j == m) && m%2==0) break;
        if ((i == n && j == m) && m%2==1) break;
    }
    tj[i][j] = a[ts];
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (tj[i][j] == s){
                cout << j << " " << i;
                return 0;
            }
        }
    }
    return 0;
}
