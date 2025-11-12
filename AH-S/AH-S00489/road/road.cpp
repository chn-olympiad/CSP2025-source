#include<bits/stdc++.h>
using namespace std;

//qianxiangxing
const int MAXN=1e4+5,MAXM=1e6+5;
int cnt=1;
struct Edge{
    int from;
    int to;
    int val;
}e[MAXM];
void addedge(int u,int v,int w){
    e[cnt].from=u;
    e[cnt].to=v;
    e[cnt].val=w;
    cnt++;
}

//binchaji
int fa[MAXN];
inline void start(int n){
    for(int i=0;i<=n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(fa[x]==x){
        return x;
    }else{
        return fa[x]=find(fa[x]);
    }
}
inline void Union(int x,int y){
    int rootx=find(x);
    int rooty=find(y);
    fa[rootx]=rooty;
}

//paixv
bool cmp(Edge a,Edge b){
    return a.val<b.val;
}
int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
        addedge(v,u,w);
    }
    for(int i=1;i<=k;i++){
        int improve_val;cin>>improve_val;
        for(int j=1;j<=n;j++){
            int w;cin>>w;
            addedge(i+n,j,w+improve_val);
            addedge(j,i+n,w+improve_val);
        }
    }
    sort(e+1,e+n*k*2+10,cmp);
    for(int i=1;i<=n*k*2+10;i++){
        cout <<e[i].from<<' '<<e[i].to<<' '<<e[i].val<<"\n";
    }
    int sum,num=0;

    for(int i=1;i<=n*k*2;i++){
        if(num==n-1)break;
        int x=find(e[i].from);
        int y=find(e[i].to);
        if(x!=y){
            sum+=e[i].val;
            Union(e[i].from,e[i].to);
            if(e[i].to<=n)num++;
        }
    }

    cout<<sum;

    return 0;
}
