#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=1e5+5;
int n,m,c[N],ans;
char s[N];int sum;
bool vis[N];int siz;
int a[N];
void dfs(int len){
    if(len==n){
        int pre=0;
        for(int i=1;i<=n;++i){
            if(c[a[i]]<=pre||s[i]=='0')pre++;
        }//cout<<'\n';
        if(n-pre>=m)ans++;
        return ;
    }
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            vis[i]=true;
            a[len+1]=i;
            dfs(len+1);
            a[len+1]=0;
            vis[i]=false;
        }
    }
}

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>s[i];
    for(int i=1;i<=n;++i)cin>>c[i];
    if(n<=10){
        dfs(0);
        cout<<ans%mod;
    }
    else{
        int cnt=0;
        for(int i=1;i<=n;++i){
            if(c[i]==0)++cnt;
        }
        if(n-cnt<m)cout<<0;
        else{
            int res=1;
            for(int i=1;i<=n;++i)
            res=res*i%mod;
            cout<<res;
        }
    }
    return 0;
}