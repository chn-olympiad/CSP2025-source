#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
const int N=505;
const int mod=998244353;
int n,m,ans,c[N],vis[N],p[N];
char s[N];
void dfs(int u){
    if(u==n+1){
        int nt=0;
        for(int i=1;i<=n;i++){
            if(nt>=c[p[i]])nt++;
            else if(s[i]=='0')nt++;
        }
        if(n-nt>=m)ans++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            p[u]=i;
            dfs(u+1);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;int tot=0,ok=n;
    for(int i=1;i<=n;i++)cin>>s[i],tot+=s[i]-'0';
    for(int i=1;i<=n;i++)cin>>c[i],ok-=(c[i]==0);
    dfs(1);
    cout<<ans<<endl;
}