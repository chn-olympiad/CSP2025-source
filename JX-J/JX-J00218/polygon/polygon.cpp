#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010],ma=-1,g,ans,tim;
namespace e_e{
void dfs(int pos){
    if(pos==n+1){
        ans=0;
        g=0;
        ma=-1;
        for(int i=1;i<=n;i++){
            if(vis[i]==1){
               ans+=a[i];
               g++;
               if(a[i]>ma) ma=a[i];
            }
        }
        if(ans>(ma*2)&&g>=3) {
            tim++;
            tim%=998244353;
        }
        return;
    }
    for(int i=0;i<=1;i++){
        vis[pos]=i;
        dfs(pos+1);
    }
    }
    int main(){
        dfs(1);
        cout<<tim;
        return 0;
    }
}
namespace n_3{
    int main(){
    for(int i=1;i<=n;i++){
        ans+=a[i];
        ma=max(a[i],ma);
    }
    if(ans>(ma*2)) cout<<1;
    else cout<<0;
    return 0;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<3) cout<<0;
    else if(n==3){
        n_3::main();
    }
    else{
        e_e::main();
    }
    return 0;
}
