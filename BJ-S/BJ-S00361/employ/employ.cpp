#include<bits/stdc++.h>
using namespace std;
// #define debug
typedef long long ll;
int s[100050],c[100005];
int n,m;
int mod=998244353;
namespace solve1{
    void work(){
        int ans=1;
        for(int i=1;i<=n;i++){
            ans=ans*i%mod;
        }
        cout<<ans;
        return ;
    }
}
namespace solve2{
    int ans=0;
    bool vis[100050];
    void dfs(int p,int f){
        #ifdef debug
        cout<<p<<" "<<f<<endl;
        #endif
        if(p==n+1){
            if(p-1-f>=m){
                ans++;
            }
            return;
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            vis[i]=1;
            if(f>=c[i])dfs(p+1,f+1);
            else if(s[p]==0)dfs(p+1,f+1);
            else dfs(p+1,f);
            vis[i]=0;
        }
    }
    void work(){
        dfs(1,0);
        cout<<ans<<endl;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool allone=1;
    int cnt=0;
    for(int i=1;i<=n;i++){
        char c;
        cin>>c;
        if(c=='0')s[i]=0,allone=0,cnt++;
        else s[i]=1;
    }
    int c0=0;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        if(c[i]==0)c0++;
    }
    if(c0+cnt>m){
        cout<<0<<endl;
        return 0;
    }
        solve2::work();
    return 0;
}