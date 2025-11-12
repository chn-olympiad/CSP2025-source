#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], n, sum[N], k;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    long long ans = 0, last = 1;
    map<long long, bool> mp;
    mp[0] = true;
    for(int i = 1; i <= n; i ++){
        if(a[i] == k){
            last = i + 1;
            mp.clear();
            mp[sum[i] ^ k] = true;
            ans ++;
        }else{
            if(mp[sum[i]] == true){
                mp.clear();
                mp[sum[i] ^ k] = true;
                ans ++;
                last = i + 1;
            }else{
                mp[sum[i] ^ k] = true;
            }
        }
    }
    cout << ans;
    return 0;
}
