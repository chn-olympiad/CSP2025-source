#include<bits/stdc++.h>
using namespace std;
int n,a[6000],vis[6000];
long long ans;
const long long N = 998244353;
void dfs(int k,int tim,int last){
    if(tim==k){
        int m = 0,su = 0;
        for(int i=1;i<=n;i++){
            if(vis[i]){
                su+=a[i];m = max(a[i],m);
            }
        }
        if(su>2*m) ans++;
    }else{
        for(int i=last+1;i<=n;i++){
            vis[i] = true;
            dfs(k,tim+1,i);
            vis[i] = false;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(i,0,0);
        memset(vis,false,sizeof(vis));
        ans%=N;
    }
    cout<<ans;
    return 0;
}
