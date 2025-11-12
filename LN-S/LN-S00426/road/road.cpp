#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
struct bian{
    int x;
    int y;
    int w;
    friend bool operator < (bian a,bian b){
        return a.w<b.w;
    }
    friend bool operator > (bian a,bian b){
        return a.w>b.w;
    }
};
int n,m,k;
vector<bian> cz;
vector<bian> zz;
priority_queue<bian,vector<bian>,greater<bian> > pq;
int par[10025];
int find(int id){
    if(id==par[id]){
        return id;
    }
    return par[id]=find(par[id]);
}
ll scs(int n){
    ll ret=0;
    while(!pq.empty()){
        pq.pop();
    }
    zz.clear();
    for(int i=1;i<=n;i++){
        par[i]=i;
    }
    for(int i=0;i<cz.size();i++){
        pq.push(cz[i]);
    }
    while(!pq.empty()){
        bian tmp=pq.top();
        pq.pop();
        int fx=find(tmp.x);
        int fy=find(tmp.y);
        if(fx!=fy){
            par[fx]=fy;
            zz.push_back(tmp);
            ret+=tmp.w;
        }
    }
    return ret;
}
vector<bian> bj[1100];
int a[15][10005];
int c[15];
bool flagA;
inline int lowbit(int shu){
    return shu&(-shu);
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    flagA=true;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        bian tmp;
        scanf("%d%d%d",&tmp.x,&tmp.y,&tmp.w);
        cz.push_back(tmp);
    }
    for(int i=1;i<=k;i++){
        scanf("%d",&c[i]);
        if(c[i]!=0){
            flagA=false;
        }
        bool yl=false;
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0){
                yl=true;
            }
        }
        if(!yl){
            flagA=false;
        }
    }
    if(flagA){
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                cz.push_back({n+i,j,a[i][j]});
            }
        }
        ll ans=scs(n+k);
        printf("%lld\n",ans);
        return 0;
    }
    ll ans=scs(n);
    swap(zz,bj[0]);
    for(int i=1;i<=k;i++){
        cz.clear();
        for(int j=1;j<=n;j++){
            cz.push_back({n+i,j,a[i][j]});
        }
        for(int j=0;j<bj[0].size();j++){
            cz.push_back(bj[0][j]);
        }
        ll fans=scs(n+k);
        fans+=c[i];
        ans=min(ans,fans);
        int dq=0;
        dq|=(1<<(i-1));
        swap(zz,bj[dq]);
    }
    //qiu chu 1 ge xiang zhen de shu liang
    for(int i=1;i<(1<<k);i++){
        int lb=lowbit(i);//yan zheng yi xia
        if(lb==i){
            continue;
        }
        int sy=i^lb;
        cz.clear();
        for(int j=0;j<bj[sy].size();j++){
            cz.push_back(bj[sy][j]);
        }
        for(int j=0;j<bj[lb].size();j++){
            cz.push_back(bj[lb][j]);
        }
        ll fans=scs(n+k);
        for(int j=1;j<=k;j++){
            if((i>>(j-1))&1){
                fans+=c[j];
            }
        }
        ans=min(fans,ans);
        swap(zz,bj[i]);
    }
    printf("%lld\n",ans);
    return 0;
}