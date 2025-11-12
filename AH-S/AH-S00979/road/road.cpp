#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4+10;
int n,m,k,u,v,wi,ans=0x3f3f3f3f3f3f3f3f;
struct node{
    int to,w;
};
vector<node> a[N];
struct xz{
    int c,p[N];
}b[20];
int mn[N][N],fx[N][N];
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    const char endl = '\n';
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>wi;
        a[u].push_back({v,wi});
        a[v].push_back({u,wi});
    }
    for(int i=1;i<=k;i++){
        cin>>b[i].c;
        for(int j=1;j<=n;j++){
            cin>>b[i].p[j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<a[i].size();j++){
            if(mn[i][a[i][j].to]){
                mn[i][a[i][j].to]=min(mn[i][a[i][j].to],a[i][j].w);
            }else{
                mn[i][a[i][j].to]=a[i][j].w;
            }
        }
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(int l=j+1;l<=n;l++){
                if(mn[j][l]) mn[j][l]=min(mn[j][l],b[i].c+b[i].p[j]+b[i].p[l]);
                else mn[j][l]=b[i].c+b[i].p[j]+b[i].p[l];
            }
        }
    }
    memset(fx,0x3f3f3f3f3f3f3f3f,sizeof(fx));
    for(int i=1;i<=n;i++){
        for(int j=0;j<n;j++){
            fx[i][a[i][j].to]=min(fx[i][a[i][j].to],mn[i][a[i][j].to]);
        }
    }
    for(int i=1;i<=n;i++){
        ans=min(ans,fx[n][i]);
    }
    cout<<ans;
    return 0;
}
