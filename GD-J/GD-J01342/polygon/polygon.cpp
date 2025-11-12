#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans;
int su[5005];
int mod=998244353;
int a[5005];
unordered_map<string,int> mp;
void dfs(int s,int maxx,int sum,string str){
    if(sum>maxx*2&&!mp[str]){
        ans++;
        if(ans>=mod)ans-=mod;
        mp[str]=1;
    }
    if(s==n+1)
        return;
    if(su[s]+sum<=maxx*2)return;
    dfs(s+1,maxx,sum,str);
    dfs(s+1,max(a[s],maxx),sum+a[s],str+to_string(s)+" ");
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,greater<int>());
    for(int i=1;i<=n;i++)su[i]=su[i-1]+a[i];
    dfs(1,0,0,"");
    cout<<ans;
    return 0;
}
