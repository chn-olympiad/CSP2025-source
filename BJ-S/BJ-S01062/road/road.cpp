#include<bits/stdc++.h>
using namespace std;
int n,m,k,top,kt[15],rd[15][10004];
long long ans;
int fa[10016],jj[15];
struct sss{
    int u,v,w,op;
}ed[3000006];
bool cmp(sss a,sss b){
    return a.w<b.w;
}
inline int gt(int x){
    if(fa[x]==x)return x;
    return fa[x]=gt(fa[x]);
}
inline void mg(int a,int b){
    a=gt(a),b=gt(b);
    fa[a]=b;
}
inline void krs(int k){
    ans=0;
    for(int i=1;i<=n+k;i++)fa[i]=i;
    
    int now=0,ji=0;
    while(ji<n+k-1 && now<=top){
        if(gt(ed[now].u)!=gt(ed[now].v) && jj[ed[now].op]==1){
            mg(ed[now].u,ed[now].v);
            ans+=ed[now].w;
            ji++;
        }
        now++;
    }
    if(ji!=n+k-1)ans=0x3f3f3f3f3f3f3f;
}
long long nmin=0x3f3f3f3f3f3f3f3f;
inline void dfs(int now,int sum,long long fy){
    if(now==k){
        jj[0]=1;
        krs(sum);
        nmin=min(nmin,ans+fy);
        return;
    }
    jj[now+1]=1;
    dfs(now+1,sum+1,fy+kt[now+1]);
    jj[now+1]=0;
    dfs(now+1,sum,fy);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    int nmax=0;
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        ed[++top]=((sss){a,b,c,0});
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&kt[i]);
        nmax=max(nmax,kt[i]);
        for(int j=1;j<=n;j++){
            scanf("%d",&rd[i][j]);
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            ed[++top]=((sss){n+i,j,rd[i][j],i});
        }
    }
    sort(ed+1,ed+top+1,cmp);
    if(nmax==0){
        for(int i=0;i<=k;i++){
            jj[i]=1;
        }
        krs(k);
        printf("%lld",ans);
        return 0;
    }
    else{
        dfs(0,0,0);
        printf("%lld",nmin);
    }
}