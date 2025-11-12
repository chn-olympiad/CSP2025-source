#include<bits/stdc++.h>
using namespace std;
#define ll long long

void pre(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
}

const int M=1e6+6;
const int N=1e4+4;
const int INF=0x7fffffff;
int n,m,k;
int w,u,v;
ll ans;

struct node{
    int u,v,w;
}e[M<<2];
int cnt=0;


//bing cha ji
int fa[N];
int find(int x){
    if(x==fa[x]) return x;
    else return fa[x]=find(fa[x]);
}

void add(node x){
    int u=x.u, v=x.v, w=x.w;
    int fu=find(u),fv=find(v);
    if(fu==fv) return;

    fa[fu]=fv;
    ans+=w;
}

//prim
bool cmp(node a,node b){
    return  a.w<b.w;
}
void prim(){
    sort(e+1,e+cnt,cmp);
    //for(int i=1;i<=m;i++) cout<<e[i].w<<" ";
    for(int i=1;i<=m;i++) add(e[i]);
}

void init(){
    cin>>n>>m>>k;

    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        e[++cnt]=(node){u,v,w};
    }

    for(int i=1;i<=k;i++){
        int temp;
        int tmp[n+1];
        cin>>temp;
        for(int k=1;k<=n;k++){
            cin>>tmp[k];
            for(int j=k-1;j>0;j--){
                //cout<<k<<" "<<j<<endl;
                e[++cnt]=(node){k,j,tmp[k]+tmp[j]};
            }
        }
    }
}

int main(){

    pre();
    init();
    prim();
    cout<<ans<<endl;

    return 0;
}
