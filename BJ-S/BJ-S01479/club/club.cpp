#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        int a[N]={},dp[N]={},n,ans=0;
        cin>>n;
        int m=n/2;
        for(int i=1;i<=n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            for(int j=m;j>=1;j--){
                dp[j]=max(dp[j],dp[j-1]+a);
                ans=max(ans,dp[j]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
