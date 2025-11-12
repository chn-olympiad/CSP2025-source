#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long rs[10001][10001];
long long ts[10001],dp[10001];
long long n,m,k;
long long u,v,w,c;
long long cnt=0,ans=0;
vector<long long>vp;
int main(){
    freopen("road3.in", "r", stdin);
    //freopen("road1.ans", "w", stdout);
    cin>>n>>m>>k;
    for(long long i=0;i<=n;i++){
        dp[i]=9999999999;
        for(long long j=0;j<=n;j++){
            rs[i][j]=9999999999;
        }
    }
    for(long long i=1;i<=m;i++){
        cin>>u>>v>>w;
        if(rs[u][v]==0)rs[u][v]=w;
        else rs[u][v]=rs[v][u]=min(rs[u][v],w);
    }
    for(long long i=1;i<=k;i++){
        cin>>c;
        for(long long j=1;j<=n;j++)cin>>ts[j];
        for(long long u=1;u<=n;u++){
            for(long long v=1;v<=n;v++){
                rs[v][u]=rs[u][v]=min(rs[u][v],ts[v]+ts[u]+c);
            }
        }
    }
    dp[1]=0;
//    for(long long u=1;u<=n;u++){
//            for(long long v=2;v<=n;v++){
//                dp[v]=min(dp[v],rs[u][v]);
//            }
//    }
//    for(long long i=1;i<=n;i++)ans+=dp[i];
    for(long long u=1;u<=n;u++){
            for(long long v=u+1;v<=n;v++){
                vp.push_back(min(dp[v],rs[u][v]));
            }
    }
    sort(vp.begin(),vp.end());
    for(long long i=0;i<n-1;i++){
        ans+=vp[i];
    }
    cout<<ans;
    return 0;
}
