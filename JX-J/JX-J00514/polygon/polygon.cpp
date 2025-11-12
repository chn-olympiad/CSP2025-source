#include <bits/stdc++.h>
using namespace std;
#define LL long long
const LL mod=998244353;
const LL N=5000;
LL n,l;
LL ans;
LL a[N+5];
LL f[N+5];
LL sz[N+5];
LL jc[N+5];
LL dp[N+5][N+5];
bool cmp(LL x,LL y){
    return x<y;
}
int main (){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[abs(a[i]-a[j])]=1;
        }
    }
    for(int i=0;i<=N;i++){
        if(f[i]==1){
            sz[l++]=i;
        }
    }
    sort(a,a+n+1,cmp);
    /*for(int i=0;i<l;i++){
        cout<<sz[i]<<' ';
    }
    cout<<'\n';
    for(int i=0;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<'\n';*/
    for(int i=1;i<=n;i++){
        for(int j=0;j<l;j++){
            if(a[i]>sz[j]){
                dp[i][j]++;
            }
            dp[i][j]+=dp[i-1][j];
            int I=lower_bound(sz,sz+l,sz[j]-a[i])-sz;
            dp[i][j]+=dp[i-1][I];
            dp[i][j]%=mod;
            //printf("%d %d %d %d %d\n",i,j,I,a[I],dp[i][j]);
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<l;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';*/
    for(int i=2;i<n;i++){
        int I=lower_bound(sz,sz+l,a[i+1])-sz;
        ans+=dp[i][I];
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
