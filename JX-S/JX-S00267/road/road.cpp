#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    int n , m , k , s = 0;
    cin>> n >> m >> k;
    int u[10005] , v[10005] , w[1000005] , c[15] , a[15][10005];
    for(int i = 1; i <= m; i++){
        cin>> u[i] >> v[i] >> w[i];
    }
    for(int i = 1;i <= k; i++){
        cin>> c[i];
        for(int j = 1; j <= m; j++){
            cin>> a[i][j];
        }
    }
    if(k == 0){
        for(int i = 1; i <= m; i++){
            s += w[i];
        }
        cout<< s;

    }
    return 0;
}
