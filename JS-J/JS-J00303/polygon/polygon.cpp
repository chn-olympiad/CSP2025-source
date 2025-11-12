#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,ans,s[5005],l[5005];
void dfs(int dep,int sum,int c){
    if(dep==c){
        if(sum>l[c]) ans++;
        ans%=mod;
        return;
    }
    if(sum+s[c-1]-s[dep-1]<=l[c]) return;
    dfs(dep+1,sum+l[dep],c);
    dfs(dep+1,sum,c);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i];
    stable_sort(l+1,l+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+=l[i];
    for(int i=n;i>=1;i--) dfs(1,0,i);
    cout<<ans%mod;
    return 0;
}
//Hope to have a good ending.