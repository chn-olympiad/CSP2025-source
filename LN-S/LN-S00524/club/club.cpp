#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
using ll=long long;
ll dt[N][3];
ll ans=0;
int T,n;
ll si2,si3;
void dfs(int x,ll v,int t1,int t2,int t3){
    if(x==n+1)ans=max(ans,v);
    else{
        if(t1+1<=n/2)dfs(x+1,v+dt[x][1],t1+1,t2,t3);
        if(t2+1<=n/2)dfs(x+1,v+dt[x][2],t1,t2+1,t3);
        if(t3+1<=n/2)dfs(x+1,v+dt[x][3],t1,t2,t3+1);
    }
    return;
}
void dfs2(int x,ll v,int t1,int t2,int t3){
    if(x==n+1)ans=max(ans,v);
    else{
        if(t1+1<=n/2)dfs(x+1,v+dt[x][1],t1+1,t2,t3);
    }
    return;
}
void dfs3(int x,ll v,int t1,int t2,int t3){
    if(x==n+1)ans=max(ans,v);
    else{
        if(t1+1<=n/2)dfs(x+1,v+dt[x][1],t1+1,t2,t3);
        if(t2+1<=n/2)dfs(x+1,v+dt[x][2],t1,t2+1,t3);
    }
    return;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(dt,0,sizeof(dt));
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&dt[i][j]);
                si2+=dt[i][2];si3+=dt[i][3];
            }
        }
        if((!si2)&&(!si3))dfs2(1,0ll,0,0,0);
        if(!si3)dfs3(1,0ll,0,0,0);
        else dfs(1,0ll,0,0,0);
        printf("%lld\n",ans);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}