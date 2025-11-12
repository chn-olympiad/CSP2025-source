#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],used[5005],ans,yhsj[5005][5005],Mod=998244353;
void dfs(long long w){
    if(w==n){
        long long genshu=0,cdh=0,maxn=0;
        for(long long i=1;i<=n;i++)if(used[i])maxn=max(maxn,a[i]),genshu++,cdh+=a[i];
        if(genshu>=3&&cdh>maxn*2){
            ans++;
        }
        return;
    }
    used[w+1]=0;
    dfs(w+1);
    used[w+1]=1;
    dfs(w+1);
    used[w+1]=0;
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<=22){
        for(long long i=1;i<=n;i++)cin>>a[i];
        dfs(0);
        cout<<ans;
        cout<<'\n';
        return 0;
    }
    yhsj[1][1]=1;
    for(long long i=2;i<=n+1;i++)
        for(long long j=1;j<=i;j++)yhsj[i][j]=(yhsj[i-1][j]+yhsj[i-1][j-1])%Mod;
    for(long long i=3;i<=n;i++)ans=(ans+yhsj[n+1][i+1])%Mod;
    cout<<ans;
    cout<<'\n';
    return 0;
}
