#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[105],c[100],a[105][105],ans=0;
void dfs(int x,int t,int sum){
    if(m<t){
        ans=max(ans,sum);
    }
    if(f[a[x][1]]==0){
    f[a[x][1]]=1;
    dfs(a[x][1],t+1,sum+a[x][3]);
    f[a[x][1]]=0;
    }
    if(f[a[x][2]]==0){
    f[a[x][2]]=1;
    dfs(a[x][2],t+1,sum+a[x][3]);
    f[a[x][2]]=0;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++)
            cin>>a[i][j];
    }
    if(k==0){
        for(int i=1;i<=m;i++)
        dfs(i,1,0);
        cout<<ans;
    }
    return 0;
}
