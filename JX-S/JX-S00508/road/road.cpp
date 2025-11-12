#include<bits/stdc++.h>
#define il inline
#define reg register
#define rep(i,a,b) for(reg int (i)=(a);(i)<=(b);++(i))
#define drep(i,a,b) for(reg int (i)=(a);(i)>=(b);--(i))
#define pb push_back
#define ins insert
#define ll long long
#define int ll
using namespace std;
const int N=1e4+20,M=1e6+10;
int fa[N];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
struct EDGE{
    int x,y,w;
    bool operator < (const EDGE X)const{
        return w<X.w;
    }
}e[M];
vector<EDGE>ed,now;
int c[15][N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    rep(i,1,n)fa[i]=i;
    rep(i,1,m){
        cin>>e[i].x>>e[i].y>>e[i].w;
    }
    sort(e+1,e+m+1);
    int ans=0;
    rep(i,1,m){
        int fax=find(e[i].x),fay=find(e[i].y);
        if(fax!=fay){
            ans+=e[i].w;
            fa[fax]=fay;
            ed.pb(e[i]);
        }
    }
    // cerr<<ans<<'\n';
    rep(i,1,k){
        rep(j,0,n){
            cin>>c[i][j];
        }
    }
    int S=(1<<k)-1;
    rep(i,0,S){
        now=ed;
        int res=0;
        rep(j,0,k-1){
            if((i>>j)&1){
                res+=c[j+1][0];
                rep(l,1,n)now.pb((EDGE){j+1+n,l,c[j+1][l]});
            }
        }
        rep(i,1,n+10)fa[i]=i;
        sort(now.begin(),now.end());
        for(auto edg:now){
            int fax=find(edg.x),fay=find(edg.y);
            if(fax!=fay){
                fa[fax]=fay;
                res+=edg.w;
            }
        }
        ans=min(ans,res);
    }
    cout<<ans<<'\n';
    return 0;
}
// 2:30 -- 22:30