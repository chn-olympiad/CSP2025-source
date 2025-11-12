#include <bits/stdc++.h>
#define MAXN 10003
#define MAXM 1000003
#define inf 1000000003
using namespace std;
int n,m,K;
struct ROAD_FIX{
    int u; int v; int val;
    bool operator<(const ROAD_FIX &B) const{
        return val<B.val;
    }
}c[MAXM]; //city
struct ROAD_ADD{
    int v; int val;
    bool operator<(const ROAD_ADD &B) const{
        return val<B.val;
    }
}r[13][MAXN]; //rural
int b[13]; //build
bool mark[13]; int cnt[13];
long long ans=1000000000000000003;
int fa[MAXN+10];
int find(int x) {while (x!=fa[x]) x=fa[x]=fa[fa[x]]; return x;}
void meiju(int x,int p){
    if (x==K){
        for (int i=1;i<=n+K;i++) fa[i]=i;
        for (int i=0;i<=K;i++) cnt[i]=1;
        int tot=0; long long res=0;
        for (int i=1;i<=K;i++) if (mark[i]) res+=b[i];
        // cerr<<"ok "<<p<<'\n';
        while (tot<n+p-1){
            int minpos=0,minval=c[cnt[0]].val;
            for (int i=1;i<=K;i++){
                if (!mark[i]) continue;
                if (r[i][cnt[i]].val<minval) {minpos=i; minval=r[i][cnt[i]].val;}
            }
            int pos=cnt[minpos];
            cnt[minpos]++;
            if (minpos==0){
                int faa=find(c[pos].u),fab=find(c[pos].v);
                if (faa==fab) continue;
                fa[faa]=fab; //random!!
                tot++; res+=c[pos].val;
                // cerr<<"add:"<<c[pos].u<<' '<<c[pos].v<<' '<<c[pos].val<<'\n';
            } else { //n+minpos
                int faa=find(n+minpos),fab=find(r[minpos][pos].v);
                if (faa==fab) continue;
                fa[faa]=fab;
                tot++; res+=r[minpos][pos].val;
                // cerr<<"omg\n";
            }
        }
        ans=min(ans,res);
        // for (int i=1;i<=K;i++) cerr<<mark[i]<<' ';
        // cerr<<"res:"<<res<<" "<<tot<<' '<<n<<' '<<p<<'\n';
        return;
    }
    mark[x+1]=0;
    meiju(x+1,p);
    mark[x+1]=1;
    meiju(x+1,p+1);
    return;
}
int main(){
    // freopen("road4.in","r",stdin);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>K;
    for (int i=1;i<=m;i++){
        cin>>c[i].u>>c[i].v>>c[i].val;
    }
    sort(c+1,c+1+m); c[m+1].val=inf;
    for (int i=1;i<=K;i++){
        cin>>b[i];
        for (int j=1;j<=n;j++){
            r[i][j].v=j;
            cin>>r[i][j].val;
        }
        sort(r[i]+1,r[i]+1+n);
        // for (int j=1;j<=n;j++) cerr<<r[i][j].val<<' '; cerr<<'\n';
        r[i][n+1].val=inf;
    }
    meiju(0,0);
    cout<<ans<<'\n';
    return 0;
}