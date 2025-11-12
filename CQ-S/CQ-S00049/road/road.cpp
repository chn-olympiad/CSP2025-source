/*
Author: Shunpower in CSP-S2025

我感到 soul cries
灵魂被 sold out
但不会懈怠 腐烂被嗅到
炙热的心才是最好解药
2025AMBITION with my freestyle
*/
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi first
#define se second
#define fr1(i,a,b) for(int i=(a);i<=(b);i++)
#define fr2(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
using namespace std;
const int N=1e4+20;
const int M=1e6+10;
int n,m,k;
struct E{
    int u,v,w;
} e[M];
int c[11];
E intree[N];
vector <pii> ext[11];
vector <int> bits;
struct dsu{
    int f[N];
    void init(int n){
        fr1(i,1,n) f[i]=i;
    }
    int find(int x){return f[x]=(f[x]==x?x:find(f[x]));}
    void merge(int x,int y){
        f[find(x)]=find(y);
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
} f,d;
ll res,ans;
int cnt;
int poi[11];
void calc(){
    d.init(n+10);
    poi[0]=1;
    fr1(i,1,k) poi[i]=0;
    fr1(i,1,cnt){
        if(res>=ans) return;
        pii newe;
        int w=1e9+1;
        while(poi[0]<=n-1&&d.same(intree[poi[0]].u,intree[poi[0]].v)) poi[0]++;
        if(poi[0]<=n-1){
            if(w>intree[poi[0]].w){
                newe=mp(intree[poi[0]].u,intree[poi[0]].v);
                w=intree[poi[0]].w;
            }
        }
        for(auto i:bits){
            while(poi[i]<=n-1&&d.same(ext[i][poi[i]].fi,n+i)) poi[i]++;
            if(poi[i]<=n-1){
                if(w>ext[i][poi[i]].se){
                    newe=mp(n+i,ext[i][poi[i]].fi);
                    w=ext[i][poi[i]].se;
                }
            }
        }
        res+=w;
        d.merge(newe.fi,newe.se);
    }
    ans=min(ans,res);
}
#define shun cute
int main(){
#ifdef shun
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
#endif
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    fr1(i,1,m) cin>>e[i].u>>e[i].v>>e[i].w;
    fr1(i,1,k){
        cin>>c[i];
        fr1(j,1,n){
            int w;
            cin>>w;
            ext[i].pb(mp(j,w));
        }
        sort(ext[i].begin(),ext[i].end(),[](pii &x,pii &y){
            return x.se<y.se;
        });
    }
    sort(e+1,e+m+1,[](E &x,E &y){
        return x.w<y.w;
    });
    int tot=0;
    f.init(n);
    fr1(i,1,m){
        int u=e[i].u,v=e[i].v;
        if(f.same(u,v)) continue;
        f.merge(u,v);
        tot++;
        intree[tot]=e[i];
    }
    ans=1e18;
    fr1(mask,0,(1<<k)-1){
        bits.clear();
        res=0;
        fr1(i,0,k-1) if((mask>>i)&1) bits.pb(i+1),res+=c[i+1]; 
        // cout<<mask<<endl;
        cnt=n+__builtin_popcount(mask)-1;
        calc();
        // if(res==292758174){
        //     cout<<mask<<endl;
        //     fr1(i,1,n) cout<<vis[i]<<" \n"[i==n];
        // }
    }
    cout<<ans<<'\n';
    // cerr<<clock()<<endl;
    return 0;
}
/*
注意只考到18:30
last 15min, NOI Linux for big samples
never stop thinking
Stage 9
冷静。冷静。冷静。

g++ -O2 -std=c++14 a.cpp -o a
*/