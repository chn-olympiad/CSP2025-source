#include<bits/stdc++.h>
using namespace std;
int n,m,k,con[15],nn,ne;
int p[11000050];
struct Edge{
    int u,v,w;
    bool fl;
    bool operator <(const Edge& E)const{
        return w<E.w;
    };
}edges[1100050];
int findx(int x){
    if(p[x]!=x) p[x]=findx(p[x]);
    return p[x];
}
void kruskal(){
    sort(edges+1,edges+n+1);
    int cnt=0,res=0;
    for(int i=1;i<=n;i++){
        int a=edges[i].u,b=edges[i].v,c=edges[i].w;
        int pa=findx(a),pb=findx(b);
        if(pa!=pb){
            p[a]=b;
            if(edges[i].fl){
                res+=con[i-ne];
                nn++;
            }
            cnt++;
            res+=c;
        }
        if(cnt==nn-1){
            cout<<res;
            exit(0);
        }
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        edges[i].fl=false;
        ne=i;
    }
    for(int i=ne+1;i<=k+ne;i++){
        cin>>con[i-ne];
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            edges[j+ne*(i-ne)].u=i,edges[j+ne*(i-ne)].v=j,edges[j+ne*(i-ne)].w=x;
            edges[j+ne*(i-ne)].fl=true;
        }
    }
    nn=n;
    for(int i=1;i<=n;i++) p[i]=i;
    kruskal();
    return 0;
}
