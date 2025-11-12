#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
int sum[500010];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        sum[i]=sum[i-1]^x;
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if((sum[i-1]^sum[j])==k){
                ans++;
                i=j;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
