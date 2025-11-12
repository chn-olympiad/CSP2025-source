#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mo=998244353;
const int N=105;
string s;
int bin[N],c[N];
int a[N],vis[N];
int n,m,ans=0;
void dfs(int t){
    if(t==n+1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0') cnt++;
            else{
                if(c[a[i]]<=cnt) cnt++;
            }
        }
        if(n-cnt>=m) ans++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        a[t]=i;
        vis[i]=1;
        dfs(t+1);
        vis[i]=0;
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    cin>>s;
    s="_"+s;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(1);
    cout<<ans<<"\n";
}