#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Rof(i,j,k) for(int i=j;i>=k;--i)
#define eb emplace_back

using namespace std;
using ll=long long;
using db=double;
using vi=vector<int>;

const int N=1e5+10;
const int M=3e6+10;
const ll inf=2e18;

int n,m,k;
int mn[N];
int c[20],b[20][N];
ll ans=0;
struct E{
    int u,v,w;
}a[M],tmp[M];
bool cmp(E e1,E e2){return e1.w<e2.w;}
int fa[N];
int ff(int u){
    return (u==fa[u]?u:fa[u]=ff(fa[u]));
}

void work(int st){
    For(i,1,n){fa[i]=i;}
    ll cost=0;
    For(i,1,k){
        if((st>>(i-1))&1){cost+=c[i];}
    }
    // For(i,1,k){if((st>>(i-1))&1){cout<<i<<' ';}}
    // cout<<cost<<'\n';
    // cout<<'\n';
    int tm=0;
    For(i,1,m){tmp[++tm]=a[i];}
    For(i,1,n){
        For(j,1,n){
            if(i==j){continue;}
            For(p,1,k){
                if((st>>(p-1))&1){
                    tmp[++tm]={i,j,b[p][i]+b[p][j]};
                    // cout<<i<<' '<<j<<' '<<b[p][i]+b[p][j]<<'\n';
                }
            }
        }
    }
    // cout<<".....\n";
    sort(tmp+1,tmp+1+tm,cmp);   
    For(i,1,tm){
        if(ff(tmp[i].u)==ff(tmp[i].v)){continue;}
        cost+=tmp[i].w;
        // cout<<tmp[i].u<<' '<<tmp[i].v<<' '<<tmp[i].w<<'\n';
        fa[ff(tmp[i].u)]=ff(tmp[i].v);
    }
    ans=min(ans,cost);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin>>n>>m>>k;
    For(i,1,n+1){
        fa[i]=i;
    }
    For(i,1,m){
        cin>>a[i].u>>a[i].v>>a[i].w;
    }
    bool st=1;
    For(i,1,k){
        cin>>c[i];
        if(c[i]!=0){st=0;}
        For(j,1,n){cin>>b[i][j];}
    }
    sort(a+1,a+1+m,cmp);
    For(i,1,m){
        if(ff(a[i].u)==ff(a[i].v)){continue;}
        ans+=a[i].w;
        fa[ff(a[i].u)]=ff(a[i].v);
    }

    if(k==0){
        cout<<ans<<'\n';
        return 0;
    }

    For(st,0,(1<<k)-1){
        work(st);
    }

    cout<<ans<<'\n';

    return 0;
}