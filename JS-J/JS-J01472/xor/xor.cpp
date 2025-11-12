#include<bits/stdc++.h>
using namespace std;

int a[500005] , n , k , cnt = 0;

void solve(){
    int start = 1 , ans = 0;
    while(1){
        int endd = n + 1;
        for(int i = start ; i <= endd ; i ++){
            int q = 0;
            for(int j = i ; j <= endd ; j ++){
                q ^= a[j];
                if(q == k){
                    endd = j;
                    break;
                }
            }
        }
        if(endd > n){
            break;
        }
        ans ++;
        start = endd + 1;
    }
    cout << ans;
}

void solve1(){
    int ans = 0 , start = 0 , endd = 0;
    for(int i = 1 ; i <= n ; i ++){
        if(a[i] == k){
            ans ++;
        }
    }
    cout << ans;
}

int main(){
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    cin >> n >> k;

    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i];
        if(a[i] == k){
            cnt ++;
        }
    }
    if(n > 5000){
        solve1();
    }
    else solve();
    return 0;
}
