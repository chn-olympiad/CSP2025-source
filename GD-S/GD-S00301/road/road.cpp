#include<bits/stdc++.h>
#define ll long long
#define fo(i,x,y) for(int i=(x);i<=(y);++i)
#define fu(i,x,y) for(int i=(x);i<(y);++i)
#define fd(i,x,y) for(int i=(x);i>=(y);--i)
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=2e4+5,M=1e6+5,K=15;
const ll inf=1e18;
int n,m,k,f[N],c[N],h[N],cnt[N],st[N];
ll ans=inf;
struct nd{int x,y,z;}e[M],e2[K][N];
int cmp(nd x,nd y){return x.z<y.z;}
int fnd(int x){return x==f[x]?x:f[x]=fnd(f[x]);}
int main(){
    freopen("road.in","r",stdin);
    // freopen("road3.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    fo(i,1,m){
        int x,y,z;cin>>x>>y>>z;
        e[i]=(nd){x,y,z};
    }
    sort(e+1,e+1+m,cmp);
    fo(i,1,n)f[i]=i;
    int t=0;
    fo(i,1,m){
        auto [x,y,z]=e[i];
        x=fnd(x);y=fnd(y);
        if(x==y)continue;
        f[x]=y;e[++t]=e[i];
    }
    fo(i,1,k){
        cin>>c[i];
        fo(j,1,n){
            int x;cin>>x;
            e2[i][j]=(nd){i+n,j,x};
        }
        sort(e2[i]+1,e2[i]+1+n,cmp);
    }
    int w=1<<k;
    fu(i,0,w){
        fo(j,1,n+k)f[j]=j,cnt[j]=j<=n;
        int o=__builtin_popcount(i),nw=1;
        ll s=0;int ln=0;
        fu(j,0,k)if(i>>j&1){
            s+=c[j+1];
            h[++ln]=j+1;st[ln]=1;
        }
        fo(j,1,n-1+o*n){
            nd x=e[nw];int fl=0;
            if(cnt[fnd(1)]==n)break;
            fo(l,1,ln)if(st[l]<=n){
                nd y=e2[h[l]][st[l]];
                if(y.z<x.z)x=y,fl=l;
            }
            if(!fl)++nw;else ++st[fl];
            x.x=fnd(x.x);x.y=fnd(x.y);
            if(x.x==x.y)continue;
            s+=x.z;f[x.x]=x.y;cnt[x.y]+=cnt[x.x];
            if(s>=ans){s=inf;break;}
        }
        ans=min(ans,s);
    }
    cout<<ans;
    cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
}