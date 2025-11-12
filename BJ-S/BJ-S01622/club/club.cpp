#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,a[maxn],b[maxn],c[maxn],dp[maxn][maxn][maxn],ans,tst,sum=0;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
   freopen("club.in","r",stdin);
   freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ans=-1;
        tst=0;
        cin>>n;
        memset(dp,-0x3f,sizeof(dp));
        for(int i=1;i<=n;i++){
                cin>>a[i]>>b[i]>>c[i];
                if(b[i]!=0 || c[i]!=0) tst=1;
        }
        if(tst==0){
            sort(a+1,a+1+n,cmp);
            for(int i=1;i<=n/2;i++) sum+=a[i];
            cout<<sum;
            continue;
        }
        dp[0][0][0]=0;
        for(int i=0;i<=n/2;i++){
            for(int j=0;j<=n/2;j++)
                for(int k=0;k<=n/2;k++){
                    if(i+j+k==0 || i+j+k>n) continue;
                    if(i!=0) dp[i][j][k]=dp[i-1][j][k]+a[i+j+k];
                    if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+b[i+j+k]);
                    if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+c[i+j+k]);
                    if(i+j+k==n) ans=max(ans,dp[i][j][k]);
                }
        }
        cout<<ans<<endl;
    }
    return 0;
}
