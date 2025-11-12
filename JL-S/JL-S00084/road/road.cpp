#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+3,M=1e4+10;
int n,m,k,awa_cnt,ans=1e18;
int c[22],a[22][M];
bool vis[N];
struct Edges{
    int a,b,c;
}edge[N],mst[N],awa[N];
bool cmp(Edges x,Edges y){return x.c<y.c;}
int p[N];
int mst_cnt=0;
int find(int x){
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}
void get_MST(){
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=m;i++){
        int a=edge[i].a,b=edge[i].b;
        if(find(a)!=find(b)){
            p[find(a)]=find(b);
            mst[++mst_cnt]=edge[i];
        }
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>edge[i].a>>edge[i].b>>edge[i].c;
    sort(edge+1,edge+1+m,cmp);
    get_MST();
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++) cin>>a[i][j],awa[++awa_cnt]={i+n,j,a[i][j]};
    }
    sort(awa+1,awa+1+awa_cnt,cmp);
    for(int sta=0;sta<(1<<k);sta++){
        int res=0;
        for(int i=1;i<=k;i++){
            vis[i]=(sta>>(i-1)&1);
            if(vis[i]) res+=c[i];
        }
        for(int i=1;i<=n+k;i++) p[i]=i;
        for(int awacnt=1,mstcnt=1;;){
            if(res>ans) break;
            if(awacnt>awa_cnt&&mstcnt>mst_cnt) break;
            if(awacnt<=awa_cnt){
                if(mstcnt>mst_cnt||awa[awacnt].c<=mst[mstcnt].c){
                    if(vis[awa[awacnt].a-n]==0){
                        awacnt++;
                        continue;
                    }
                    int a=awa[awacnt].a,b=awa[awacnt].b;
                    if(find(a)!=find(b)){
                        p[find(a)]=find(b);
                        res+=awa[awacnt].c;
                    }
                    awacnt++;
                    continue;
                }
            }
            int a=mst[mstcnt].a,b=mst[mstcnt].b;
            if(find(a)!=find(b)){
                p[find(a)]=find(b);
                res+=mst[mstcnt].c;
            }
            mstcnt++;
            continue;
        }
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
    return 0;
}