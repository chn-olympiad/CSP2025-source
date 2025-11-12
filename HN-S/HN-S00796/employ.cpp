#include<bits/stdc++.h>
#define int long long
const int N=505,M=998244353,INF=1e9;
using namespace std;
int n,m,s[N],c[N],b[N],p[N],ans=0;char ch;
void ck(){
    int ct=0;
    for(int i=1;i<=n;i++)if(s[i]==0||ct>=c[p[i]])ct++;
    if(n-ct>=m)ans=(ans+1)%M;
}
void dfs(int x){
    if(x==n+1){ck();return;}
    for(int i=1;i<=n;i++)if(!b[i])
        b[i]=1,p[x]=i,dfs(x+1),b[i]=0;
}
signed main(){
    ios::sync_with_stdio(false);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>ch;
        s[i]=(ch=='1');
    }
    for(int i=1;i<=n;i++)cin>>c[i];
    dfs(1);
    cout<<ans<<endl;
    return 0;
}