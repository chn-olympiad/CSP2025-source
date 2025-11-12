#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,ans;
int c[505];
int vis[505];
string s;
int k=0;
void dfs(int x,int t,int k){
    int kk=k;
    if(kk>=c[x]||s[t]=='0') kk++;
    if(n-k<m) return;
    if(t==n&&n-kk>=m){
        ans++;
        ans%=mod;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i,t+1,kk);
            vis[i]=0;
        }
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i,1,0);
        vis[i]=0;
    }
    cout<<ans;
    return 0;
}
