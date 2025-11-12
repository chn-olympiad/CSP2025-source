#include<bits/stdc++.h>
using namespace std;
long long dp[5010][5010],ans; //the sticks number and the sticks address
int n,a[10000],d[10000];
const long long m=998244353;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    for(int i=3;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(j<i || d[j]-d[j-i]<=2*a[j]){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=(dp[i][j-1]*2+1);
                ans+=dp[i][j];
                ans%=m;
            }
            dp[i][j]%=m;
        }
    }
    cout<<ans;
    return 0;
}
