#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans;
int n;
int a[5005];
int vis[10005];
void dfs(int p,int sum,int maxx,int k){
    if(p>3){
        if(sum>maxx*2){
            ans++;
            ans%=mod;

        }

    }
    if(p>n)return;
    for(int i=k+1;i<=n;i++){
        if(vis[i]==0 ){
            vis[i]=1;
            dfs(p+1,sum+a[i],max(maxx,a[i]),i);
            vis[i]=0;
        }

    }


}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}
