#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n, m=3, w[maxn][5], dp[maxn][5], v[maxn][5][5];
struct node {
    int a,b,c;
}a[maxn];
bool cmp(node x,node y) {
    int ta=x.a,tb=x.b,tc=x.c, ya=y.a,yb=y.b,yc=y.c;
    if(tc>tb) swap(tc,tb);
    if(tb>ta) swap(tb,ta);
    if(yc>yb) swap(yc,yb);
    if(yb>ya) swap(yb,ya);
   // if(ta!=ya) return ta>ya;
    //if(tb!=yb) return tb>yb;
    //if(tc!=yc) return tc>yc;
    //if(ta+yc!=tc+ya) return ta+yc>tc+ya;
    if(tc==yc&&tc==0) {
        if(ta+yb!=tb+ya)
            return ta+yb>tb+ya;
        return ta>tb;
    }
    if(ta+yc!=tc+ya) return ta+yc>tc+ya;
    return tb+yc>tc+yb;
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b>>a[i].c;
    memset(dp,0,sizeof dp);
    memset(v,0,sizeof v);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++) w[i][1]=a[i].a,w[i][2]=a[i].b,w[i][3]=a[i].c;
    for(int i=1;i<=m;i++) {
        dp[1][i]=w[1][i];
        v[1][i][i]=1;
    }
    for(int i=2;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            //dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
            for(int k=1;k<=m;k++) {
                if(v[i-1][k][j]+1<=n/2) {
                    if(dp[i-1][k]+w[i][j]>=dp[i][j]) {
                        if((dp[i-1][k]+w[i][j]==dp[i][j])&&(v[i][j][j]<=v[i-1][k][j]+1)) continue;
                        dp[i][j] = dp[i-1][k]+w[i][j];
                        v[i][j][1]=v[i-1][k][1],v[i][j][2]=v[i-1][k][2],v[i][j][3]=v[i-1][k][3];
                        v[i][j][j]++;
                    }
                }
            }
            //cout<<dp[i][j]<<"    "<<v[i][j][1]<<' '<<v[i][j][2]<<' '<<v[i][j][3]<<'\n';
        }
        //cout<<'\n';
    }
    cout<<max(dp[n][1],max(dp[n][2],dp[n][3]))<<'\n';
    return;
}

void solve1() {
    cin>>n;
    bool flg = 1;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>w[i][j];
    for(int i=1;i<=n;i++) if(w[i][3]) flg = 0;
    if(flg) {

    }
}


int main() {
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int _; cin>>_;
    while(_--) solve();
    return 0;
}
