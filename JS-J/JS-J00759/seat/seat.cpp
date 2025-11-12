#include<bits/stdc++.h>
using namespace std;
int n , m , a[1000001] , ans[1001][1001] , k = 1 , ia , ja , r;
int main(){
    freopen("seat.in" , "r" , stdin);
    freopen("seat.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1 ; i <= n * m ; i ++){
        cin >> a[i];
        if(i == 1) r = a[i];
    }
    for(int i = 1 ; i <= n * m ; i ++){
        for(int j = 1 ; j <= n * m - i ; j ++){
            if(a[j] < a[j + 1]) swap(a[j] , a[j + 1]);
        }
    }
    for(int j = 1 ; j <= m ; j ++){
        if(j & 1){
            for(int i = 1 ; i <= n ; i ++){
                ans[i][j] = a[k ++];
                if(ans[i][j] == r){
                    ia = j;
                    ja = i;
                }
            }
        }else{
            for(int i = n ; i >= 1 ; i --){
                ans[i][j] = a[k ++];
                if(ans[i][j] == r){
                    ia = j;
                    ja = i;
                }
            }
        }
    }
    cout << ia << ' ' << ja;
    return 0;
}
