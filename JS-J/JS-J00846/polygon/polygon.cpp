#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mods=998244353;
int n,a[5010],ans,m;
bool vis[5010];
void qpl(int step,int mx,int sum){
    if(step==m&&sum-mx>mx){
        ans=(ans%mods+1)%mods;
        return;
    }
    if(step==m&&sum-mx<=mx) return;
    for(int i=1;i<=n;i++){
        vis[i]=1;
        qpl(step+1,max(a[i],mx),sum+a[i]);
        vis[i]=0;
    }
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=3;i<=n;i++){
        m=i;
        qpl(1,0,0);
    }
    cout<<ans;
    return 0;
}
