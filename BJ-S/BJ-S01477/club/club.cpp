#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=1e5+10;
ll t,n,a[N][3],dp[N][3];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<3;j++){
                dp[i][j]=-1e10;
            }
        }
        for(ll i=1;i<=n;i++){
            cin>>a[i][0]>>a[i][1]>>a[i][2];
        }
        for(ll i=0;i<3;i++){
            dp[1][i]=a[1][i];
        }
        for(ll i=2;i<=n;i++){
            for(ll j=0;j<3;j++){
                dp[i][j]=max(dp[i][j],max({dp[i-1][0],dp[i-1][1],dp[i-1][2]})+a[i][j]);
            }
        }
        cout<<max({dp[n][0],dp[n][1],dp[n][2]})<<'\n';
    }
    return 0;
}
