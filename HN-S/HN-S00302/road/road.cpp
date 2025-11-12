#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+17,M=1e6+10;
int n,m,k,a[11][N],f[N],cnt=0,id[N],sec[N],op[N],c[13],lp;
ll ans;
struct node{
    int l,r,w;
}eg[M*2],ned[M*2];
vector<node>v;
inline bool cmp(node a,node b){
    return a.w<b.w;
}
void clear(){
    for(int i=1;i<=n+k;i++)
        f[i]=i;
    return;
}
inline int find(int x){
    if(f[x]==x) return x;
    return f[x]=find(f[x]);
}
inline ll kus(){
    ll sum=0,tot=0;
    clear();
    for(int i=1;i<=cnt;i++){
        if(ned[i].l>n&&op[ned[i].l-n]==0) continue;
        if(tot==n-1+lp) return sum;
        int fl=find(ned[i].l),fr=find(ned[i].r);
        if(fl==fr) continue;
        sum+=ned[i].w;
        tot++;
        f[fl]=fr;
    }
    return sum;
}
inline void dfs(int x){
    if(x==k+1){
        ll num=0;
        lp=0;
        for(int i=1;i<=k;i++)
            num+=op[i]*c[i],lp+=op[i];
        ans=min(ans,kus()+num);
        return;
    }
    op[x]=1;
    dfs(x+1);
    op[x]=0;
    dfs(x+1);
    return;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>eg[i].l>>eg[i].r>>eg[i].w;
    clear();
    sort(eg+1,eg+m+1,cmp);
    for(int i=1;i<=m;i++){
        if(cnt==n-1) break;
        int fl=find(eg[i].l),fr=find(eg[i].r);
        if(fl==fr) continue;
        f[fl]=fr;
        cnt++;
        ned[cnt]=eg[i];
        ans+=eg[i].w;
    }
    // cout<<cnt<<' '<<ans<<'\n';
    for(int i=1;i<=k;i++){
        cin>>c[i];
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            cnt++;
            ned[cnt]=node{i+n,j,a[i][j]};
        }
    }
    sort(ned+1,ned+cnt+1,cmp);
    dfs(1);
    cout<<ans;
    return 0;
}