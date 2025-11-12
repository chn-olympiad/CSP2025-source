#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5;
typedef long long ll;
ll n,m,k,kk[11][N],tu[N][N],c[11],dis[N],maxx;
bool f[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&k);
    for(int i=1;i<=m;i++){
        ll aa,bb,cc;
        scanf("%lld%lld%lld",&aa,&bb,&cc);
        tu[aa][bb]=cc;
        tu[bb][aa]=cc;
    }
    for(int i=1;i<=k;i++){
        scanf("%lld",&c[i]);
        for(int j=1;j<=n;j++){
            scanf("%lld",&kk[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!tu[i][j]){
                    tu[i][j]=tu[j][i]=2e18;
                }
        }
    }
    for(int o=1;o<=k;o++)
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(c[o]+kk[o][i]+kk[o][j]<tu[i][j]){
                    tu[i][j]=tu[j][i]=c[o]+kk[o][i]+kk[o][j];
                }
            }
        }
    for(int i=1;i<=n;i++){
        dis[i]=2e18;
    }
    dis[1]=0;
    for(int i=1;i<=n;i++){
        ll minn=2e18,q;
        for(int j=1;j<=n;j++){
            if(dis[j]<minn&&!f[j]){
                minn=dis[j];q=j;
            }
        }
        f[q]=1;maxx+=minn;
        //cout<<maxx<<endl;
        for(int j=1;j<=n;j++){
            if(f[j])continue;
            if(tu[q][j]<dis[j]){
                dis[j]=tu[q][j];
            }
        }
    }
    cout<<maxx<<endl;
}
