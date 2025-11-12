#include <bits/stdc++.h>
#define MAXN 20010
#define MAXM 1000010
#define MAXK 30
#define int long long
#define HAJIMINANBEILVDOU 0
using namespace std;
typedef struct edge{
    int a,b;
    int weight;
    bool operator < (edge &eee){
        return weight<eee.weight;
    }
} edge;
edge arr[MAXM];
edge eg[2*MAXM];
int gaizao[MAXK];
int g_rc[MAXK][MAXN];
int fa[MAXN];
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return;
    else fa[fx]=fy;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;cin>>n>>m>>k;
    int ans=0x3f3f3f3f;
    for(int i=1;i<=m;i++){
        cin>>arr[i].a>>arr[i].b>>arr[i].weight;
    }
    for(int i=1;i<=k;i++){
        cin>>gaizao[i];
        for(int j=1;j<=n;j++) cin>>g_rc[i][j];
    }

    if(k==0){
        for(int i=1;i<=n;i++) fa[i]=i;
        sort(arr+1,arr+1+m);
        int aaans=0;
        for(int i=1;i<=m;i++){
            if(find(arr[i].a)!=find(arr[i].b)) merge(arr[i].a,arr[i].b),aaans+=arr[i].weight;
        }
        cout<<aaans;
    }
    else{
        for(int msk=0;msk<(1<<k);msk++){
            int aaans=0;
            int edge_cnt=m; int node_cnt=n; int idx;for(idx=1;idx<=m;idx++) eg[idx]=arr[idx];
            for(int i=0;i<k;i++){
                if((msk>>i)&1){
                    //bit k have
                    aaans+=gaizao[i+1];
                    edge_cnt+=n;
                    node_cnt++;
                    int node_name=n+i+1;
                    for(int j=1;j<=n;j++){
                        edge temp;
                        temp.a=node_name;
                        temp.b=j;
                        temp.weight=g_rc[i+1][j];
                        eg[idx++]=temp;
                    }
                }
            }
            for(int i=1;i<=node_cnt;i++) fa[i]=i;
            sort(eg+1,eg+edge_cnt+1);
            for(int i=1;i<=edge_cnt;i++){
                if(find(eg[i].a)!=find(eg[i].b)) merge(eg[i].a,eg[i].b),aaans+=eg[i].weight;
            }
            if(aaans<ans) ans=aaans;
        }
        cout<<ans<<endl;
    }
    return HAJIMINANBEILVDOU;
}

