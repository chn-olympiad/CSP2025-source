#include <bits/stdc++.h>

using namespace std;
int a[12][12];
int b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++){
        cin >> b[i];
    }
    int tar = b[1];
    int all1 = n*m;
    sort(b+1,b+n*m+1);
    int i = 1;
    int j = 1;
    for(int t = n*m;t >= 1;t--){
        a[i][j] = b[t];
        if(j % 2 == 0){
            i--;
            if(i < 1){
                i = 1;
                j++;
            }
        }
        else{
            i++;
            if(i > n){
                i = n;
                j++;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(a[i][j] == tar){
                cout << j << ' ' << i;
            }
        }
    }
    return 0;
}
