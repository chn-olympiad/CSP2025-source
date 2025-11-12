#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,a[5005];
void dfs(int num,int maxl,int depth,int last){
    if(num>2*maxl&&depth>=3)ans++;
    for(int i=last+1;i<=n;i++)dfs(num+a[i],max(maxl,a[i]),depth+1,i);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    dfs(0,0,0,0);
    cout<<ans%998244353;
    return 0;
}
