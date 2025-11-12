#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=505,mod=998244353;
int n,m,s[M],c[M],p[M],ans,vis[M],cnt;
char t[M];
void dfs(int x){
    if(x>n){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(c[p[i]]<=sum||s[i]==0)sum++;
        }
        if(n-sum>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(vis[i])continue;
        p[x]=i,vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>t+1;
    for(int i=1;i<=n;i++){
        s[i]=t[i]-'0';
        cin>>c[i];
    }
    if(n<=18){
        dfs(1);
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(s[i]==0)cnt++;
    }
    if(n-cnt>=m){
        ans=1;
        for(int i=1;i<=n;i++)ans=ans*i%mod;
        cout<<ans;
    }
    else{
        cout<<0;
    }
    return 0;
}