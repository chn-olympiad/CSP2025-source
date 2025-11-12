#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k;
ll a[500010];
ll sum[500010];
ll cnt[1100000];
ll ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]^a[i];
    }
    cnt[0]=1;
    for(ll r=1;r<=n;r++){
            if(a[r]==k){
            ans++;
            memset(cnt,0,sizeof(cnt));
            cnt[sum[r]]=1;
            continue;
        }
        ll x=sum[r]^k;
        if(cnt[x]==0){
            cnt[sum[r]]=1;
            continue;
        }
        ans++;
        memset(cnt,0,sizeof(cnt));
        cnt[sum[r]]=1;
    }
    cout<<ans;
    return 0;
}
