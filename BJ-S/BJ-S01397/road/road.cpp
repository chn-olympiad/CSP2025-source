#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
const int N=1e4+5,M=1e6+4;

struct edge{
    int u,v,w;
}e[M],g[M*2];

int c[15],cst[15][N];
int flg[15];
int fa[N];

int find(int x){
    if(fa[x]==x) return fa[x];
    else return fa[x]=find(fa[x]);
}

bool cmp(edge a,edge b){
    return a.w<b.w;
}

long long ANS=1e18;
void dfs(int cur,long long sum){
    if(sum>ANS) return ;
    if(cur==k+1){
        int cnt=m;
        long long ans=0;
        for(int i=1;i<=m;i++){
            g[i]=e[i];
        }
        for(int i=1;i<=k;i++){
            if(flg[i]){
                for(int j=1;j<=n;j++){
                    g[++cnt]={i+n,j,cst[i][j]};
                }
            }
        }
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        sort(g+1,g+cnt+1,cmp);
        int C=0;
        for(int i=1;i<=cnt;i++){
            u=g[i].u,v=g[i].v,w=g[i].w;
            int fu=find(u),fv=find(v);
            if(fu!=fv){
                //cout<<"edge"<<u<<' '<<v<<' '<<w<<endl;
                fa[fu]=fv;
                ans+=w;
                ++C;
            }
            if(ans+sum>ANS) return ;
            if(C==n+k-1) break;
        }
        ANS=min(ANS,ans+sum);
        //cout<<sum<<' '<<ans+sum<<endl;
        return ;
    }
    else{
        flg[cur]=1;
        dfs(cur+1,sum+c[cur]);
        flg[cur]=0;
        dfs(cur+1,sum);
    }
    return ;
}

void dfs2(int cur,long long sum){
    if(sum>ANS) return ;
    if(cur==k+1){
        int cnt=m;
        long long ans=0;
        for(int i=1;i<=m;i++){
            g[i]=e[i];
        }
        for(int i=1;i<=k;i++){
            if(flg[i]){
                for(int j=1;j<=n;j++){
                    g[++cnt]={i+n,j,cst[i][j]};
                }
            }
        }
        for(int i=1;i<=n+k;i++){
            fa[i]=i;
        }
        sort(g+1,g+cnt+1,cmp);
        int C=0;
        for(int i=1;i<=cnt;i++){
            u=g[i].u,v=g[i].v,w=g[i].w;
            int fu=find(u),fv=find(v);
            if(fu!=fv){
                //cout<<"edge"<<u<<' '<<v<<' '<<w<<endl;
                fa[fu]=fv;
                ans+=w;
                ++C;
            }
            if(ans+sum>ANS) return ;
            if(C==n+k-1) break;
        }
        ANS=min(ANS,ans+sum);
        //cout<<sum<<' '<<ans+sum<<endl;
        return ;
    }
    else{
        flg[cur]=1;
        dfs2(cur+1,sum+c[cur]);
    }
    return ;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int check=0;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        check+=c[i];
        int s=1;
        for(int j=1;j<=n;j++){
            cin>>cst[i][j];
            if(cst[i][j]==0) s=0;
        }
        check+=s;
    }
    if(check==0){
        dfs2(1,0);
    }
    else dfs(1,0);
    cout<<ANS;
}