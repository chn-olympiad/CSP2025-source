#include<bits/stdc++.h>
using namespace std;
#define int long long
int c[505];
int n,m;
string s;
const int mod=998244353;
int a[505];
bool vis[505];
int ans;
void dfs(int x){
    if(x>n){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='0'||cnt>=c[a[i]]) cnt++;
        }
        ans+=n-cnt>=m;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            a[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n==m){
        int res=1;
        for(int i=1;i<=n;i++){
            if(!s[i-1]){
                cout<<0;
                return 0;
            }
            res=res*i%mod;
        }
        cout<<res;
        return 0;
    }
    for(int i=1;i<=n;i++) a[i]=i;
    dfs(1);
    cout<<ans;
    return 0;
}