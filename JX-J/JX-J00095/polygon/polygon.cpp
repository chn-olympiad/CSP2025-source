#include<bits/stdc++.h>
using namespace std;
int n,a[5005],vis[5005]={},sum=0,ans=0;
void dfs(int x=1){
    for(int i=1;i<=n;i++){
        if(sum>2*a[i]&&x>=3){
            ans++;
            vis[i]=0;
            x=1;
            break;
        }
        sum=0;
        dfs(i);
        if(vis[i]==0){
            sum+=a[i];
            vis[i]=1;
        }
    }
    cout<<ans;
}

int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    return 0;
}
