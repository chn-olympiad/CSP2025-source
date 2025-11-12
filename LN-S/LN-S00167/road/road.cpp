#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define int long long
using namespace std;
const int N=1e4+10;
const int M=1e7+10;
// const int N=1e3+10;
// const int M=1e3+10;
int n,m,k;
int bitflag;
typedef struct edge{
    int u,v,w,enable;
} edge;

edge e[M];
int a[20];
int b[20];
int p[N];
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int cmp(edge a,edge b){
    return a.w<b.w;
}

int kruskal(){
    for(int i=1;i<=n+12;i++){
        p[i]=i;
    }
    int res=0;
    int new_cnt = 0;
    for(int i=1;i<=m;i++){
        if(e[i].enable!=-1 && !((bitflag>>(e[i].enable-1))&1)){
            continue;
        }
        int fu=find(e[i].u);
        int fv=find(e[i].v);
        if(fu!=fv){
            res+=e[i].w;
            p[fu]=fv;
        }
    }
    return res;
}

int calc_x(int bit){
    int res=0;
    for(int i=0;i<k;i++){
        res+=((bit>>i)&1)*b[i+1];
    }
    return res;
}
signed main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int enable_flag = 1;
    cin >> n >> m >> k;
    // m*=2;
    for(int i=1;i<=m;i++){
        cin >> e[i].u >> e[i].v >> e[i].w;
        e[i].enable = -1;
        // e[i+1].enable = -1;
        // e[i+1].u=e[i].v;
        // e[i+1].v=e[i].u;
        // e[i+1].w=e[i].w;
    }
    for(int i=1;i<=k;i++){
        int tmp;
        cin >> tmp;
        a[i]=i;
        b[i]=tmp;
        if(tmp!=0){
            enable_flag=0;
        }
        for(int j=1;j<=n;j++){
            e[++m].u=n+i;
            cin >> e[m].w;
            e[m].v=j;
            e[m].enable = i;
            // e[++m].u=j;
            // e[m].v=n+i;
            // e[m].w=c[i][j];
            // e[m].enable = i;
        }
    }
    sort(e+1,e+1+m,cmp);
    int res=0x3fffffffffffffff;
    if(enable_flag){
        bitflag = (1<<k)-1;
        res = min(kruskal()+calc_x(bitflag),res);
    }else{
        for(int fx=0;fx<(1<<k);fx++){
            bitflag=fx;
            // cout << fx << endl;
            res = min(kruskal()+calc_x(fx),res);
        }
    }
    printf("%lld\n",res);
}