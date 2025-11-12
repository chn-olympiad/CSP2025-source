#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],qzh[500005];
vector<int> mp[(int)pow(2,21)];
signed main(){
    freopen("xor.in","r",stdin);freopen("xor.out","w",stdout);
    int n,k;cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        qzh[i] = qzh[i-1]^a[i];
        mp[qzh[i]].push_back(i);
    }
    int f = 0,ans = 0;
    for(int i = 1;i <= n;i++){
        auto it = lower_bound(mp[qzh[i-1]^k].begin(),mp[qzh[i-1]^k].end(),i);
        if(it==mp[qzh[i-1]^k].end()) continue;
        if(i>f) ans++;
        else if(*it>=f) continue;
        f = *it;
    }
    cout << ans;
    return 0;
}
