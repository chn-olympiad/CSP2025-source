#include<bits/stdc++.h>
#define int long long 
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int N=1010,M=1000010;
int n,m,k;
int fa[N];
int v[15][N];
int c[N];
int a[N][N];
struct E{
    int x,y,w;
}e[M];
bool cmp(E a,E b){
    return a.w<b.w;
}
int find(int x){
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void solve(){
    cin>>n>>m>>k;
    rep(i,1,m){
        int x,y,w; cin>>x>>y>>w;
        e[i]={x,y,w};
    }
    rep(i,1,k){
        cin>>c[i];
        rep(j,1,n){
            cin>>a[i][j];
        }
    }
    rep(t,1,k){
        rep(i,1,n){
            fa[i]=i;
            if(k==0) v[t][i]=0x3f3f3f3f3f3f3f3f;
            else v[t][i]=a[t][i];
        }
    }
    // cout<<v[1][3]<<"sb\n";
    sort(e+1,e+m+1,cmp);
    int ans=0,tot=0;
    rep(i,1,m){
        int sum=e[i].w;
        int fx=find(e[i].x),fy=find(e[i].y);
        if(fx==fy) {
            rep(t,1,k){
                v[t][fy]=min(v[t][fx],v[t][fy]);
            }
            continue;
        }
        rep(t,1,k){
                // cout<<v[t][fx]<<' '<<v[t][fy]<<' '<<c[t]<<'\n';
            if(v[t][fx]+v[t][fy]+c[t]<sum){
                sum=v[t][fx]+v[t][fy]+c[t];
                // sum=v[t][fx]+v[t][fy]+c[t];
            }
        }
        // cout<<'\n';
        fa[fx]=fy;
        rep(t,1,k){
            // if(t==1&&fx==3)cout<<v[t][fx]<<"Sb";
            v[t][fy]=v[t][fx]=min(v[t][fx],v[t][fy]);
            
        }
        ans+=sum;
        // cout<<sum<<'\n';
        ++tot;
        if(tot==n-1) break;
    }
    // rep(t,1,k){
    //     rep(i,1,n){
    //         cout<<v[t][find(i)]<<' ';
    //     }
    //     cout<<'\n';
    // }
    cout<<ans<<'\n';
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int T=1; 
    // cin>>T;
    for(;T;--T){
        solve();
    }
    return 0;
}
/*
g++ road.cpp -o road -std=c++14 -O2 -Wall
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4

*/