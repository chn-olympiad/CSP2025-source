#include<bits/stdc++.h>
using namespace std;
int a[110];
int f[110];
int zw[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n , m;
    cin >> n >> m ;
    for(int i = 1 ; i <= n * m ; i++)cin >> a[i];
    int R = a[1];
    sort(a+1,a+(n*m)+1);
    int q = 1;
    for(int  i = n * m ; i >= 1 ; i--){
        f[q] = a[i];
        q++;
    }
    q = 1;
    for(int i = 1 ; i <= n ; i++){
        if(i % 2 == 1){
            for(int j = 1 ; j <= m ; j++){
                zw[i][j] = f[q];
                q++;
            }
        }
        else{
            for(int j = m ; j >= 1 ; j--){
                zw[i][j] = f[q];
                q++;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            if(zw[i][j] == R){
                cout << i << " " << j ;
                break;
            }
        }
    }
    return 0;
}
