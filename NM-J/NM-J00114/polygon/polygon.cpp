#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int l[550];
bool b[550];
int ans;
void dfs(int u,int sum,int ma){
    sum+=l[u];
    if(u>=n){
        if(sum>ma*2) ans++;
        ans++;
        return;
    }
    if(sum>max(ma,l[u])*2){
        dfs(u+1,sum,max(ma,l[u]));
    }
    dfs(u+1,sum-l[u],ma);
}
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];
    }
    dfs(1,0,l[1]);
    cout<<ans;
    return 0;
}
