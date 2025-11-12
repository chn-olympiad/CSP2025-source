#include <bits/stdc++.h>
using namespace std;

int n,m,k,c[15],a[15][10005],last;
int fa[10015];

struct edge{
    int u,v,w;
}e[1100005];

bool cmp(edge a,edge b){
    return a.w<b.w;
}

int find(int x){
    if(x==fa[x]){
        return x;
    }
    return (fa[x]=find(fa[x]));
}

long long kruskal(){
    for(int i=1;i<=n;i++){
        fa[i]=i;
    }
    sort(e+1,e+m+1,cmp);
    long long ans=0;
    for(int i=1;i<=m;i++){
        int x=e[i].u,y=e[i].v;
        x=find(x),y=find(y);
        if(x==y){
            e[i].w=0x3f3f3f3f;
            continue;
        }
        else{
            last=i;
            fa[x]=fa[y];
            ans+=e[i].w;
        }
    }
    return ans;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>e[i].u>>e[i].v>>e[i].w;
    }
    int fA=1;
    for(int i=1;i<=k;i++){
        cin>>c[i];
        int f=0;
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                f=1;
            }
        }
        if(!f or c[i]){
            fA=0;
        }
    }
    if(fA and 1==0){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                e[++m].u=n+i;
                e[m].v=j;
                e[m].w=a[i][j];
            }
        }
        n+=k;
        cout<<kruskal();
    }
    else{
        long long ans=kruskal();
        sort(e+1,e+m+1,cmp);
        if(m*(1<<k)>=50000000){
            m=50000000/(1<<k);
        }
        for(int s=0;s<=(1<<k)-1;s++){
            int p=0;
            int m1=m;
            long long C=0;
            for(int i=1;i<=k;i++){
                if(s>>i-1){
                    C+=c[i];
                    p++;
                    for(int j=1;j<=n;j++){
                        e[++m].u=n+p;
                        e[m].v=j;
                        e[m].w=a[i][j];
                    }
                }
            }
            n+=p;
            ans=min(ans,kruskal()+C);
            m=m1,n-=p;
        }
        cout<<ans;
    }
    return 0;
}
