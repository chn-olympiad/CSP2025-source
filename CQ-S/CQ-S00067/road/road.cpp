#include<bits/stdc++.h>
using namespace std;
#define PII array<int,2>
#define TII array<int,3>
const int maxn=2e4+5,maxm=1e6+5,maxk=15;
int n,m,k,cnt,c[maxn],fa[maxn];TII ln[maxk][maxn];long long ans=1e18;
TII jnk[maxm],lk[maxn];
TII lnk[2][1<<5][maxn];
int tot[2][1<<5];
int getfa(int x){
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>k;
    for(int i=1,u,v,w;i<=m;i++){
        cin>>u>>v>>w;
        jnk[i]=TII{w,u,v};
    }
    sort(jnk+1,jnk+1+m);for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=jnk[i][1],v=jnk[i][2],w=jnk[i][0];
        if(getfa(u)!=getfa(v)){
            lk[++cnt]=jnk[i];
            u=getfa(u);
            v=getfa(v);
            fa[u]=v;
        }
    }
    //得到了有效边
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>ln[i][j][0],ln[i][j][1]=i+n,ln[i][j][2]=j;
        }
    }
    //然后进行枚举+最小生成树——显然是可以做两个最小生成树，记录边集合，然后最小生成树合并的时候只需要合并 10^4 个节点即可
    int lm=k>>1,rm=k-lm;
    //lm
    for(int S=0;S<(1<<lm);S++){
        for(int i=1;i<n;i++){
            jnk[i]=lk[i];
        }
        m=n-1;
        for(int i=1;i<=lm;i++){
            if(S>>i-1&1){
                for(int j=1;j<=n;j++){
                    jnk[++m]=ln[i][j];
                }
            }
        }
        sort(jnk+1,jnk+1+m);for(int i=1;i<=n+k;i++)fa[i]=i;//最小生成树，开始
        for(int i=1;i<=m;i++){
            int u=jnk[i][1],v=jnk[i][2],w=jnk[i][0];
            if(getfa(u)!=getfa(v)){
                lnk[0][S][++tot[0][S]]=jnk[i];
                u=getfa(u);
                v=getfa(v);
                fa[u]=v;
            }
        }
    }
    //rm+n
    for(int S=0;S<(1<<rm);S++){
        for(int i=1;i<n;i++){
            jnk[i]=lk[i];
        }
        m=n-1;
        for(int i=1;i<=rm;i++){
            if(S>>i-1&1){
                for(int j=1;j<=n;j++){
                    jnk[++m]=ln[lm+i][j];
                }
            }
        }
        sort(jnk+1,jnk+1+m);for(int i=1;i<=n+k;i++)fa[i]=i;//最小生成树，开始
        for(int i=1;i<=m;i++){
            int u=jnk[i][1],v=jnk[i][2],w=jnk[i][0];
            if(getfa(u)!=getfa(v)){
                lnk[1][S][++tot[1][S]]=jnk[i];
                u=getfa(u);
                v=getfa(v);
                fa[u]=v;
            }
        }
    }
    //合并计算答案
    for(int S0=0;S0<(1<<lm);S0++)
    for(int S1=0;S1<(1<<rm);S1++){
        m=0;
        int i=1,j=1;
        while(i<=tot[0][S0] and j<=tot[1][S1]){
            if(lnk[0][S0][i][0]<=lnk[1][S1][j][0]){
                jnk[++m]=lnk[0][S0][i],i++;
            }else{
                jnk[++m]=lnk[1][S1][j],j++;
            }
        }
        while(i<=tot[0][S0])jnk[++m]=lnk[0][S0][i],i++;
        while(j<=tot[1][S1])jnk[++m]=lnk[1][S1][j],j++;
        //完成排序
        for(int i=1;i<=n+k;i++)fa[i]=i;//生成树预备
        long long res=0;
        for(int i=1;i<=lm;i++)if(S0>>i-1&1)res+=c[i];
        for(int i=1;i<=rm;i++)if(S1>>i-1&1)res+=c[i+lm];
        for(int i=1;i<=m;i++){
            int u=jnk[i][1],v=jnk[i][2],w=jnk[i][0];
            if(getfa(u)!=getfa(v)){
                res+=w;
                u=getfa(u);
                v=getfa(v);
                fa[u]=v;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans<<endl;
    return 0;
}