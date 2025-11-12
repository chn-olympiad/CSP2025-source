#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MOD = 998224353;
int n;
int a[50001];
int sum;
signed main(){
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    int maxn = -1;
    for(int i = 1;i <= n;i ++){
        cin >> a[i]; 
        maxn = max(maxn, a[i]);      
    }
    for(int i = 3;i <= n;i ++){
        for(int i = 1;i <= n;i ++){
            for(int j = i + 1;j <= n;j ++){
                if(abs(i - j) < 3){
                    continue;
                }
                int cnt = 0;
                for(int k = i;k <= j;k ++){
                    cnt += a[k];
                }
                if(cnt > 2 * maxn){
                    sum ++;
                }
            }
        }
    }  
    cout << sum % MOD;
    return 0;
}