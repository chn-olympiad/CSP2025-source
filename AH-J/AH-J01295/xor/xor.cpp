#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, last = 0, ans = 0;
long long k, a[N], xor_sum[N];
map<long long, int> mp;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        xor_sum[i] = xor_sum[i - 1] ^ a[i];
    }
    if(n <= 1000){
        for(int i = 1; i <= n; i++){
            for(int j = last + 1; j <= i; j++){
                if((xor_sum[i] ^ xor_sum[j - 1]) == k){
                    ans++;
                    last = i;
                    break;
                }
            }
        }
        cout << ans;
    }else{
        mp[0] = 1;
        for(int i = 1; i <= n; i++){
            long long ned = xor_sum[i] ^ k;
            if(mp[ned] == 1){
                ans++;
                mp.clear();
            }
            mp[xor_sum[i]] = 1;
        }
        cout << ans;
    }
    return 0;
}
