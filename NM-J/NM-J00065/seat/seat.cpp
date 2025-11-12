#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
	int n,m;
	int s[1000];
	int dp[n][m];
	cin >> n >> m;
	for(int i=1;i<=n;i++){
        cin >> s[i];
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i]>dp[i][j-1]){
                dp[n][m]=dp[i][j];
            }else{
            dp[n][m]=max(dp[i][j],dp[i][j+1]+s[i]);
            }

        }

  cout << dp[n][m];
  return 0;
    }
}
