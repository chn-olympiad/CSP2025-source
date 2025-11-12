#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define For(x,l,r) for(ll x=l;x<=r;++x)
#define Rof(x,l,r) for(ll x=r;x>=l;--x)
#define pb push_back

const int N = 1e4+50, M = 1e6+5, K = 15;

int n,m,k;
int c[K],a[K][N];
struct E{int u,v,w;}e[M];
vector<E> newe;
ll ans;
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool merge(int x,int y){
    int fx=find(x),fy=find(y);
    if(fx==fy) return 0;
    f[fx]=fy;
    return 1;
}
void getans(ll sc){
    ll re=0;
    For(i,1,n+k) f[i]=i;
    vector<E> ww=newe;
    sort(ww.begin(),ww.end(),[&](const E&x,const E&y){return x.w<y.w;});
    int j=0,len=ww.size();

    For(i,1,m){
        while(j<len&&ww[j].w<=e[i].w){
            if(merge(ww[j].u,ww[j].v)) re+=ww[j].w;
            j++;
        }
        if(merge(e[i].u,e[i].v)) re+=e[i].w;
    }
    
    ans=min(ans,re+sc);
}
void dfs(int i,ll sc){
    if(i>k){
        getans(sc);
        return ;
    }
    
    For(j,1,n) newe.pb({i+n,j,a[i][j]});
    dfs(i+1,sc+c[i]);
    For(j,1,n) newe.pop_back();
    dfs(i+1,sc);
}

void solve(){
    newe.clear();
    ans=2e18;
    cin>>n>>m>>k;
    For(i,1,m){
        int u,v,w;cin>>u>>v>>w;
        e[i]={u,v,w};
    }
    For(i,1,k){
        cin>>c[i];
        For(j,1,n) cin>>a[i][j];
    }
    sort(e+1,e+1+m,[&](const E&x,const E&y){return x.w<y.w;});
    dfs(1,0);
    cout<<ans<<'\n';
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
/*
1s
512

1e9 per second
*/