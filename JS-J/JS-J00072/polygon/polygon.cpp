#include <bits/stdc++.h>
using namespace std;
long long n,a[5005],ans=0;
bool vis[1005];
void dfs(int x,int num,int length){
    if(num>=3&&length>a[x]*2){
        ans=(ans+1)%998244353;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]&&i>x){
            vis[i]=true;
            dfs(i,num+1,length+a[i]);
            vis[i]=false;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    vis[0]=true;
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}
