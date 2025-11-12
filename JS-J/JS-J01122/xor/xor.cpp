#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, k, a[500003], sum[500003], last = -114514, ans;
map<int, int>mp;
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin>>n>>k;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        sum[i] = sum[i - 1] ^ a[i];
    }
    mp[0] = -1;
    for(int i = 1;i <= n;i++){
        int target = sum[i] ^ k;
        if(mp[target] && mp[target] + 1 > last)ans++, last = i;
        mp[sum[i]] = i;
    }
    cout<<ans;
}
