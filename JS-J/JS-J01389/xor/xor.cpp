#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,ans;
ll a[500005];
void dfs(ll idx,ll zh,ll cnt){
    if(zh==k){
        for(int i=idx+1;i<=n;i++){
            dfs(i,0,cnt+1);
        }
    }
    if(idx>=n){
        ans=max(ans,cnt);
        return;
    }
    zh=a[idx]^zh;
    dfs(idx+1,zh,cnt);
}
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(ll i=1;i<=n;i++){
    cin>>a[i];
   }
   for(ll i=1;i<=n;i++){
      dfs(i,0,0);
   }
   cout<<ans<<endl;
   return 0;
}
