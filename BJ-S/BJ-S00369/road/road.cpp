#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[5000001],ans,w[510],qu[11][100001],a[2005][1009],cans[501];
struct node{
    int u,v,w;
}e[5000001];
bool cmp(node x,node y){
    return x.w<y.w;
}
int find(int x){
    if(x==fa[x])return x;
    else return fa[x]=find(fa[x]);
}
int kruskal(){
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++){
        int u=find(e[i].u),v=find(e[i].v);
        //cout<<"i="<<i<<","<<u<<" "<<v<<" "<<e[i].u<<" "<<e[i].v<<" \n";
        if(u!=v){
            fa[u]=v;
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
        int u,v,w;
        cin>>e[i].u>>e[i].v>>e[i].w;
        u=e[i].u,v=e[i].v,w=e[i].w;
        a[u][v]=a[v][u]=w;
    }
    if(k==0){
        cout<<kruskal();
        return 0;
    }
    int f3=1;
    for(int i=1;i<=k;i++){
        cin>>w[i];
        if(w[i]!=0)f3=0;
        for(int j=1;j<=n;j++){
            cin>>qu[i][j];
        }
    }
    if(f3){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                int w=qu[i][j];
                e[++m].u=i;
                e[m].v=j;
                e[m].w=w;
            }
        }
        cout<<kruskal();
        return 0;
    }
    else{
        int wi=kruskal();
        ans=0;
        for(int i=1;i<=k;i++){
            int tmp=m;
            for(int j=1;j<=n;j++){
                int w=qu[i][j];
                e[++m].u=i;
                e[m].v=j;
                e[m].w=w;
            }
            cans[i]=kruskal()+w[i];
            ans=0,m=tmp;
        }
        int jia=0;
        for(int i=1;i<=k;i++){
            if(cans[i]<=wi){
                for(int j=1;j<=n;j++){
                    int w=qu[i][j];
                    e[++m].u=i;
                    e[m].v=j;
                    e[m].w=w;
                }
                jia+=w[i];
            }
        }

        cout<<kruskal()+jia;
    }
    return 0;
}
