#include<bits/stdc++.h>
using namespace std;
int a[5010];
int n;
int g[5010];
int ans=0;
void dfs(int dep,int pre){
    if(dep>=3){
        if(g[0]>g[dep]*2){
            ans++;
            ans=ans%998244353;
            /*for(int i=1;i<=dep;i++){
                cout<<g[i]<<" ";
            }
            cout<<endl;*/
        }
    }
    for(int i=pre+1;i<=n;i++){
        g[dep]=a[i];
        g[0]+=a[i];
        dfs(dep+1,i);
        g[dep]=0;
        g[0]-=a[i];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(1,0);
    cout<<ans;
    return 0;
}
