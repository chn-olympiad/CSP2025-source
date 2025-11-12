#include<bits/stdc++.h>
#define N 10015
#define M 1000005
#define K 15
using namespace std;
namespace shan{
    typedef long long ll;
    int n,m,k;
    struct edge{
        int x,y,d;
        bool operator < (const edge&y)const{
            return d<y.d;
        }
    }e[M],f[K][N];
    int prt[N];
    int getprt(int x){return prt[x]<0?x:prt[x]=getprt(prt[x]);}
    bool link(int x,int y){
        x=getprt(x);
        y=getprt(y);
        if(x==y)return 0;
        if(prt[x]<prt[y])swap(x,y);
        prt[y]+=prt[x];
        prt[x]=y;
        return 1;
    }
    int e_cnt[1<<10];
    edge dp[1<<10][N],ls[N*2];
    ll val[1<<10];int c[K];
    signed main(){
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++)
            cin>>e[i].x>>e[i].y>>e[i].d;
        sort(e+1,e+m+1);
        memset(prt,-1,sizeof prt);
        for(int i=1;i<=m;i++){
            if(link(e[i].x,e[i].y)){
                dp[0][++e_cnt[0]]=e[i];
                val[0]+=e[i].d;
            }
        }
        for(int i=0;i<k;i++){
            cin>>c[i];
            for(int j=1;j<=n;j++){
                int d;cin>>d;
                f[i][j]={n+i+1,j,d};
            }
            sort(f[i]+1,f[i]+n+1);
            for(int j=0;j<(1<<i);j++){
                memset(prt,-1,sizeof prt);
                merge(f[i]+1,f[i]+n+1,dp[j]+1,dp[j]+e_cnt[j]+1,ls+1);
                for(int k=1;k<=n+e_cnt[j];k++){
                    if(link(ls[k].x,ls[k].y)){
                        dp[j|(1<<i)][++e_cnt[j|(1<<i)]]=ls[k];
                        val[j|(1<<i)]+=ls[k].d;
                    }
                }
            }
        }
        ll minn=1e18;
        for(int i=0;i<1<<k;i++){
            for(int j=0;j<k;j++)
                if(i>>j&1)
                    val[i]+=c[j];
            minn=min(minn,val[i]);
        }
        cout<<minn;
        return 0;
    }
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    shan::main();
    return 0;
}
/*
*1900 ?
*/