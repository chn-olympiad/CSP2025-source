#include <bits/stdc++.h>
#define MAXN 50000000000005
typedef long long ll;
using namespace std;
struct an{
    ll v,w;
};
ll g[10005][10005],kt[15][10005],d[10005],b[10005],n,m,k,ans=0;
void prime(){
    d[1]=0;
    for(int ii=1;ii<=n;ii++){
        ll minn=MAXN,mpl;
        for(int i=1;i<=n;i++){
            if(b[i]==0&&d[i]<minn){
                minn=d[i];
                mpl=i;
            }
        }b[mpl]=1;
        ans+=minn;
        for(int i=1;i<=n;i++){
            if(g[mpl][i]<d[i]&&b[i]==0){
                d[i]=g[mpl][i];
            }
        }
    }
}
void adb(ll u,ll v ,ll w){
    g[u][v]=min(g[u][v],w);
    g[v][u]=min(g[v][u],w);
}
int main(){

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            g[i][j]=MAXN;
        }d[i]=MAXN;
    }
    for(int i=1;i<=m;i++){
        ll uu,vv,ww;
        cin>>uu>>vv>>ww;
        adb(uu,vv,ww);
    }for(int ii=1;ii<=k;ii++){
        ll ck;
        cin>>ck;
        for(int j=1;j<=n;j++){
            cin>>kt[ii][j];
        }for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adb(i,j,kt[ii][j]+kt[ii][i]+ck);
            }
        }
    }prime();
    cout<<ans;
    return 0;
}
