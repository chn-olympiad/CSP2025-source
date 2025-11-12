#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
    int frm,to,ds,nx;
}e[3000005],g[3000005];
int n,m,k,u,v,w,he[3000005],hg[3000005],tote,totg,c[15],a[15][10005],f[10005],cnt,s[10005],maxsz,stat,res,ans=LONG_MAX;
int im[10005],pp;
void build(int U,int V,int W){
    g[++totg]={U,V,W,hg[U]};
    hg[U]=totg;
}
int gett(int p){
    if(p==f[p])return p;
    return f[p]=gett(f[p]);
}
bool cmp(edge e1,edge e2){
    return e1.ds<e2.ds;
}
int popcnt(int p){
    int ret=0;
    int tmp=p;
    while(tmp){
        if(tmp&1)ret++;
        tmp>>=1;
    }
    return ret;
}
int kru(int stp){
    for(int i=1;i<=n;i++){
        f[i]=i;
        s[i]=1;
        im[i]=0;
    }
    for(int i=n+1;i<=n+stp;i++){
        im[i]=1;
        s[i]=1;
    }
    int ret=0;
    sort(g+1,g+m*2+n*stp*2+1,cmp);
    for(int i=1;i<=(m+n)*2;i++){
        int eu=g[i].frm;
        int ev=g[i].to;
        int ew=g[i].ds;
        int fu=gett(eu);
        int fv=gett(ev);
        if(fu!=fv){
            f[fu]=fv;
            s[fv]+=s[fu];
            im[fv]+=im[fu];
            s[fu]=s[fv];
            im[fu]=im[fv];
            ret+=ew;
            maxsz=max(maxsz,s[fv]-im[fv]);
        }
        if(maxsz>=n){
            return ret;
        }
    }
    return ret;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    maxsz=1;
    for(int i=1;i<=n;i++){
        f[i]=i;
        s[i]=1;
    }
    /*
    4 6 0
    1 2 16
    1 3 13
    1 4 14
    2 3 22
    2 4 19
    3 4 11
    */
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&u,&v,&w);
        build(u,v,w);
        build(v,u,w);
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&a[i][j]);
        }
    }
    int stcnt=(1<<k);
    for(int st=1;st<stcnt;st++){
        totg=m*2;
        pp=popcnt(st);
        for(int i=1;i<=k;i++){
            if(st&(1<<(i-1))){
                for(int j=1;j<=n;j++){
                    build(n+i,j,a[i][j]);
                    build(j,n+i,a[i][j]);
                }
                res+=c[i];
            }
        }
        res+=kru(pp);
        ans=min(ans,res);
    }
    res+=kru(pp);
    ans=min(ans,res);
    printf("%lld",ans);
    return 0;
}
