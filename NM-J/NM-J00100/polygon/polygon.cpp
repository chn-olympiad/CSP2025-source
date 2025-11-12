#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int dp[5005][5005]={};
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    int n;
    cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v.begin()+1,v.end());
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=5001;j++){
            //cout<<setw(3)<<dp[i-1][j]<<" ";
            if(i>=3&&(j>v[i])){
                ans=(ans+dp[i-1][j])%MOD;
            }
        }
        //cout<<"\n";
        for(int j=0;j<=5001;j++){
            dp[i][j]=dp[i-1][j];
        }
        for(int j=0;j<=5001;j++){
            if(j+v[i]>5000){
                dp[i][5001]=(dp[i][5001]+dp[i-1][j])%MOD;
            }
            else{
                dp[i][j+v[i]]=(dp[i][j+v[i]]+dp[i-1][j])%MOD;
            }
        }
    }
    cout<<ans;
    return 0;
}
