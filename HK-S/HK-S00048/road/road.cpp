#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN=2e4+5, MAXM=1e6+5;
ll n, m, k, fa[MAXN], sz[MAXN], c[12][MAXN], cost[12], ans, tmp, extra, mask;
struct Edge{
    ll aa, bb, cc;
    bool operator <(const Edge &o)const{
        return cc<o.cc;
    }
}e[MAXM];
multiset<Edge> st, useful;
ll Find(ll x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
void Merge(ll x, ll y){
    x=Find(x);
    y=Find(y);
    if(x!=y){
        if(sz[x]>sz[y]){
            swap(x,y);
        }
        fa[x]=y;
        sz[y]+=sz[x];
    }
}
ll Solve(){
    for(ll i=1; i<=n+k; i++){
        sz[i]=1;
        fa[i]=i;
    }
    ll aa, bb, cc, res=0;
    for(multiset<Edge>::iterator it=st.begin(); it!=st.end(); it++){
        aa=it->aa;
        bb=it->bb;
        cc=it->cc;
        if(Find(aa)!=Find(bb)){
            Merge(aa,bb);
            res+=cc;
        }
    }
    return res;
}
int main(){
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>k;
    for(ll i=1; i<=m; i++){
        cin>>e[i].aa>>e[i].bb>>e[i].cc;
    }
    sort(e+1, e+m+1);
    for(ll i=1; i<=n+k; i++){
        sz[i]=1;
        fa[i]=i;
    }
    ll aa, bb, cc;
    for(ll i=1; i<=m; i++){
        aa=e[i].aa;
        bb=e[i].bb;
        cc=e[i].cc;
        if(Find(aa)!=Find(bb)){
            Merge(aa,bb);
            useful.insert(e[i]);
            ans+=cc;
        }
    }
    for(ll i=1; i<=k; i++){
        cin>>cost[i];
        st=useful;
        for(ll j=1; j<=n; j++){
            cin>>c[i][j];
            st.insert((Edge){n+i,j,c[i][j]});
        }
        tmp=Solve()+extra+cost[i];
        if(tmp<ans){
            ans=tmp;
            extra+=cost[i];
            useful=st;
            mask|=(1<<i);
        }
    }
    for(ll i=1; i<=k; i++){
        if(!(mask>>i&1)){
            continue;
        }
        st=useful;
        for(ll j=1; j<=n; j++){
            st.erase((Edge){n+i,j,c[i][j]});
        }
        tmp=Solve()+extra-cost[i];
        if(tmp<ans){
            ans=tmp;
            extra-=cost[i];
            useful=st;
        }
    }
    cout<<ans;
    return 0;
}