#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans,mod=998244353;
string s;
int c[501],a[501];
bool vis[501];
void dfs(int x){
    if(x==n+1){
        int tmp=0,sum=0;
        for(int i=1;i<=n;++i){
            if(s[i]=='0'){
                ++tmp;
                continue;
            }
            if(tmp>=c[a[i]]){
                ++tmp;
                continue;
            }
            ++sum;
        }
        if(sum>=m) ++ans;
        return;
    }
    for(int i=1;i<=n;++i){
        if(vis[i]) continue;
        a[x]=i;
        vis[i]=1;
        dfs(x+1);
        vis[i]=0;
    }
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s="0"+s;
    for(int i=1;i<=n;++i) cin>>c[i];
    dfs(1);
    cout<<ans;
    return 0;
}
