#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,nc[110],xR;
    cin >> n >> m >> xR;
    int f = n * m - 1;
    for(int i = 0;i < f;i++){
        cin >> nc[i];
    }
    sort(nc,nc + f);
    int x = f - (upper_bound(nc,nc + f,xR) - nc),i = 1;
    while(i <= m){
        int j = 1;
        for(j;j <= n;j++){
            if(x <= 0){
                cout << i << ' ' << j;
                return 0;
            }
            x--;
        }
        i++,j--;
        for(j;j >= 1;j--){
            if(x <= 0){
                cout << i << ' ' << j;
                return 0;
            }
            x--;
        }
        i++;
    }
    return 0;
}
