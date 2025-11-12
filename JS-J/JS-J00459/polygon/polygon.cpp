#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll ans=0;
int n;
int a[100009];
int vis[100009];
void dfs(int step,int ma,int len,ll h){
    if(len>=3&&ma*2<h){
        ans++;
        ans%=998244353;
    }
    for(int i=step+1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
            dfs(i,max(a[i],ma),len+1,h+a[i]);
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
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        for(int j=1;j<=i;j++){
            vis[j]=1;
        }
        dfs(i,a[i],1,a[i]);
    }
    cout<<ans;
    return 0;
}
