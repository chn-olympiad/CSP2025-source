#include<bits/stdc++.h>
using namespace std;
int n,a[5010],vis[5010],ans;
void dfs(int x,int y,int z,int d){
    if(z>x*2&&y>3)ans++;
    for(int i=d;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(max(x,a[i]),y+1,z+a[i],i);
            vis[i]=0;
        }
    }
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++)cin>>a[i];
   dfs(0,1,0,1);
   cout<<ans;
   return 0;
}
