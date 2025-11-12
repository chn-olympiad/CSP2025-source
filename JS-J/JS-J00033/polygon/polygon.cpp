#include<bits/stdc++.h>
using namespace std;
int n,a[100005],vis[100005],ans;
void dfs(int da,int shu,int zong,int ge){
    if(ge>=3&&da*2<zong){
        ans++;
    }
    if(shu>n) return;
    if(vis[shu]==0){
        vis[shu]=1;
        dfs(max(a[shu],da),shu+1,zong+a[shu],ge+1);
    }
    else{
        vis[shu]=0;
        dfs(da,shu+1,zong,ge);
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++){
        vis[i]=1;
        dfs(a[i],i,a[i],1);
    }
    cout<<ans*2;
    fclose(stdin);
    fclose(stdout);
}
