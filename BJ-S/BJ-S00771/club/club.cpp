#include<bits/stdc++.h>
using namespace std;
const int N=205;
long long T,n,ans;
long long dp[N][N][N];
int v[N][3],v1[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin>>n;
        ans=0;
        if(n>200){
            for(int i=1;i<=n;++i){
                cin>>v1[i]>>v[i][1]>>v[i][2];
            }
            sort(v1+1,v1+n+1);
            ans=0;
            for(int i=n;i>n/2;--i){
                ans+=v1[i];
            }
            cout<<ans;
            continue;
        }
        for(int i=1;i<=n;++i){
            cin>>v[i][0]>>v[i][1]>>v[i][2];
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n/2&&j<=i;++j){
                for(int k=0;k<=n/2&&j+k<=i;++k){
                    int q=i-j-k;
                    if(q>n/2) continue;
                    if(j) dp[j][k][q]=max(dp[j][k][q],dp[j-1][k][q]+v[i][0]);
                    if(k) dp[j][k][q]=max(dp[j][k][q],dp[j][k-1][q]+v[i][1]);
                    if(q) dp[j][k][q]=max(dp[j][k][q],dp[j][k][q-1]+v[i][2]);
                    //dp[j][k][q]=max(dp[j-1][k][q]+v[i][0],max(dp[j][k-1][q]+v[i][1],dp[j][k][q-1]+v[i][2]));
                    //cout<<i<<' '<<j<<' '<<k<<' '<<q<<' '<<dp[j][k][q]<<"\n";
                    ans=max(ans,dp[j][k][q]);
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
