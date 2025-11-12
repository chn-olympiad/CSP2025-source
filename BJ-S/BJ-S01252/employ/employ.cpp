#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int a[505],n,m;
int p[505],ans;
bool vis[505];
string s;
void dfs(int cur){
    if(cur>n){
        int fl=0;
        for(int i2=1;i2<=n;i2++){
            int i=p[i2];
            if(fl>=a[i]||s[i2-1]=='0'){
                fl++;
            }
        }
        if(n-fl>=m) ans++;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            p[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=10){
        dfs(1);
        cout<<ans;
        return 0;
    }
    if(m==n){
        bool f=1;
        for(int i=0;i<n;i++){
            if(s[i]=='0'||a[i+1]==0) f=0;
        }
        if(!f){
            cout<<0;
        }
        else{
            int ans=1;
            for(int i=1;i<=n;i++){
                ans=ans*i%mod;
            }
            cout<<ans;
        }
        return 0;
    }
    cout<<0;
    return 0;
}
