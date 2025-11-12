#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

const int K=12,M=1000005;

int n,m,k;
struct edge{
    int u,v,w;
} e[K*3][M];
int cnt;
int c[M];
bool cmp(const edge& a,const edge& b){
    return a.w<b.w;
}

int fa[M];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int a,int b){
    fa[find(a)]=find(b);
}
void initdsu(){
    for(int i=1;i<=n+k;++i){
        fa[i]=i;
    }
}

struct pnode{
    int id;
    edge val;
};bool operator<(const pnode& a,const pnode& b){
    return (a.val.w<b.val.w);
}

ll ans=0;
bool chosen[M];
int p[K*3],mx[K*3];
void krumerge(int o,int s,int t){
    //cout<<o<<' '<<s<<' '<<t<<" ==================="<<endl;
    int lst=0;
    pnode a,b;
    a={s,e[s][1]};
    b={t,e[t][1]};
    mx[o]=mx[s]+mx[t]-n+1;
    //cout<<s<<' '<<t<<' '<<mx[s]<<' '<<mx[t]<<' '<<mx[o]<<endl;
    p[s]=p[t]=1;
    int cnt=0;
    initdsu();
    while(cnt<mx[o]){
        pnode tp=(a<b?a:b);
        edge ce=tp.val;
        //cout<<ce.u<<' '<<ce.v<<' '<<ce.w<<' '<<tp.id<<' '<<mx[tp.id]<<' '<<p[tp.id]<<endl;
        //tp=(a<b?a:b);
        //ce=tp.val;
        //cout<<ce.u<<' '<<ce.v<<' '<<ce.w<<' '<<tp.id<<' '<<mx[tp.id]<<' '<<p[tp.id]<<endl;
        if(find(ce.u)!=find(ce.v)){
            ++cnt;
            e[o][++lst]=ce;
            merge(ce.u,ce.v);
            //cout<<"merged!"<<endl;
        }if(p[tp.id]<mx[tp.id]){
            if(tp.id==s) a={tp.id,e[tp.id][++p[tp.id]]};
            else b={tp.id,e[tp.id][++p[tp.id]]};
        }else{
            if(tp.id==s) a={tp.id,{0,0,2000000000}};
            else b={tp.id,{0,0,2000000000}};
        }
    }
    return ;
}
void dfs(int cur){
    if(cur>k){
        ll cans=0;
        for(int i=1;i<=k;++i){
            cans+=chosen[i]*c[i];
        }for(int i=1;i<=mx[cnt];++i){
            cans+=e[cnt][i].w;
        }ans=min(ans,cans);
        return ;
    }chosen[cur]=false;
    dfs(cur+1);
    ++cnt;
    krumerge(cnt,cnt-1,cur);
    //cout<<"----> "<<cnt<<endl;
    //for(int i=1;i<=mx[cnt];++i){
    //    cout<<e[cnt][i].u<<' '<<e[cnt][i].v<<' '<<e[cnt][i].w<<endl;
    //}cout<<"====> "<<endl;
    chosen[cur]=true;
    dfs(cur+1);
    --cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    //n=10000;m=1000000;k=10;
    cnt=k+1;
    //cout<<n<<' '<<m<<' '<<k<<endl;
    for(int i=1;i<=m;++i){
        cin>>e[0][i].u>>e[0][i].v>>e[0][i].w;
        //e[0][i].u=rand()%n+1;e[0][i].v=rand()%n+1;e[0][i].w=rand();
    }for(int i=1;i<=k;++i){
        cin>>c[i];
        //c[i]=rand()%1000;
        mx[i]=n;
        for(int j=1;j<=n;++j){
            cin>>e[i][j].w;
            //e[i][j].w=rand()%1000;
            e[i][j].u=i+n;
            e[i][j].v=j;
        }
    }
    sort(e[0]+1,e[0]+m+1,cmp);
    for(int i=1;i<=k;++i){
        sort(e[i]+1,e[i]+n+1,cmp);
    }
    initdsu();
    ll cans=0,cnt=0;
    mx[k+1]=n-1;
    for(int i=1;i<=m;++i){
        if(find(e[0][i].u)!=find(e[0][i].v)){
            //cout<<cnt<<' '<<e[0][i].u<<' '<<e[0][i].v<<endl;
            merge(e[0][i].u,e[0][i].v);
            e[k+1][++cnt]=e[0][i];
            cans+=e[0][i].w;
        }
    }ans=cans;
    //cout<<cnt<<' '<<ans<<endl;

    chosen[k+1]=true;
    dfs(1);
    cout<<ans;
    return 0;
}
