#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105] , n , m , fx = 1 , nx = 1 , ny = 1 , xc , idx;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i ++){
        cin >> a[i];
    }
    xc = a[1];
    sort(a + 1 , a + n * m + 1 , greater<int>());
    while(1){
        idx ++;
        if(a[idx] == xc){
            cout << nx << ' ' << ny;
            return 0;
        }
        ny += fx;
        if(ny > m){
            ny = m;
            nx ++;
            fx = -1;
        }
        else if(ny < 1){
            ny = 1;
            nx ++;
            fx = 1;
        }
    }
    return 0;
}

