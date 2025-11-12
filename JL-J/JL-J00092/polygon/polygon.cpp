#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=5e3+10,mod=998244353;
int n,ans=0,mx=-1,a[N],c[M][M];
void dfs(int i,int mx,int sum){
//    cout<<i<<' '<<mx<<' '<<sum<<'\n';
    if(i==n+1){if(mx*2<sum){ans++;ans%=mod;}return;}
    dfs(i+1,max(mx,a[i]),sum+a[i]);
    dfs(i+1,mx,sum);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
    if(mx==1){
        for(int i=0;i<=n;i++)c[0][i]=1;
        for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)c[i][j]=c[i-1][j-1]+c[i][j-1];
        for(int i=3;i<=n;i++)ans+=c[i][n];
        cout<<ans;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans%mod;
    return 0;
}
/*
5
1 2 3 4 5
*/
