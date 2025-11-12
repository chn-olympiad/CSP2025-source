#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k;
int a[10005][10005],b[15][10005],c[15][2];
long long ans;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(a,0x3f3f3f3f,sizeof a);
    for(int i=1;i<=n;i++)
        a[i][i]=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int i=1;i<=k;i++){
        cin>>c[i][0];
        for(int j=1;j<=n;j++)
            cin>>b[i][j];
    }
    for(int pq=1;pq<=n;pq++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                a[i][j]=min(a[i][pq]+a[pq][j],a[i][j]);
    for(int pq=1;pq<=k;pq++)
        for(int i=1;i<=n;i++){
            int j=i+1;
            if(c[pq][1] && b[pq][i]+b[pq][j]<a[i][j])
                a[i][j]=b[pq][i]+b[pq][j];
            else if(b[pq][i]+b[pq][j]+c[pq][0]<a[i][j]){
                c[pq][1]=1;
                a[i][j]=b[pq][i]+b[pq][j]+c[pq][0];
            }
            ans+=a[i][j];
        }
    cout<<ans<<endl;
    return 0;
}