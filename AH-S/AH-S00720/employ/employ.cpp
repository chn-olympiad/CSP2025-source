#include<bits/stdc++.h>
using namespace std;
long long ans,a[1010],n,m,c[1010],vis[3628810][12],tot=1,vis2[20];
char s;
void dfs(long long now,long long fa){
    if(now>n){
        tot++;
        for(int i=1;i<now;i++){
            vis[tot][i]=vis[tot-1][i];
        }
        return;
    }
    for(int i=1;i<=n;i++){
        if(vis2[i]==0){
            vis2[i]=1;
            vis[tot][now]=i;
            dfs(now+1,i);
            vis2[i]=0;
        }
    }
    return;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=s-'0';
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    dfs(1,0);
    ans=0;
    for(int i=1;i<tot;i++){
        long long jj=0,zrs=0;
        for(int j=1;j<=n;j++){
            long long x=vis[i][j];//people
            if(jj>=c[x]){
                jj++;
                continue;
            }
            if(a[j]==1){
                zrs++;
            }
            else{
                jj++;
            }
        }
        if(zrs>=m){
            ans=(ans+1)%998244353;
        }
    }
    printf("%lld",ans);
    return 0;
}
