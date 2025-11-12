#include<bits/stdc++.h>

using namespace std;

int n,m,k;
long long minans=1e18;
int c[30];
int a[30][10010];
vector<array<int,3>> eds_froce;
vector<array<int,3>> eds_xz;
vector<array<int,3>> eds;

int bcj[10010];

int findbcj(int x) {
    if(bcj[x]==x) {
        return x;
    } else {
        return bcj[x]=findbcj(bcj[x]);
    }
}

bool xxz[20];
void dfs(int x) {
    if(x>=k+1) {
        eds_xz.clear();
        long long xz_fee=0;
//        cerr<<"build_xz ";
        for(int i=1; i<=k; i++) {
            if(xxz[i]) {
//                cerr<<i<<" ";
//                cerr<<endl;
                xz_fee+=c[i];
                int u=n+i;
                for(int v=1; v<=n; v++) {
                    eds_xz.push_back({a[i][v],u,v});
//                    cerr<<"connect "<<u<<" "<<v<<" "<<a[i][v]<<endl;
                }
            }
        }
        eds.clear();
        for(auto i:eds_froce){
            eds.push_back(i);
        }
        for(auto i:eds_xz){
            eds.push_back(i);
        }
        for(int i=1; i<=(n+k); i++) {
            bcj[i]=i;
        }
//        cerr<<1<<endl;
        sort(eds.begin(),eds.end());
//        cerr<<2<<endl;
        long long ans=0;
        for(auto i:eds) {
            int x=i[1];
            int y=i[2];
            long long w=i[0];
            int fx=findbcj(x);
            int fy=findbcj(y);
            if(fx==fy) {
                continue;
            }
            ans+=w;
            bcj[fx]=fy;
        }
//        cerr<<3<<endl;
//        cerr<<"cost "<<ans<<" "<<xz_fee<<endl;
        minans=min(minans,ans+xz_fee);
        return ;
    } else {
        xxz[x]=1;
        dfs(x+1);
        xxz[x]=0;
        dfs(x+1);
    }
    return ;
}

int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) {
        bcj[i]=i;
    }
    for(int i=1; i<=m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        eds_froce.push_back({w,u,v});
    }
    for(int i=1; i<=k; i++) {
        cin>>c[i];
        for(int j=1; j<=n; j++) {
            cin>>a[i][j];
        }
    }
    dfs(1);
    cout<<minans<<endl;
    return 0;
}
