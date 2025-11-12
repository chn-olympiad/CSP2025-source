#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int dp[10005][10005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
    for(int i=1;i<=n;i++){
        dp[i][1]=!(k^a[i]);
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            int un=0;
            for(int u=i-j+1;u<=i;u++){
                un=un^a[u];
            }
            dp[i][j]=(un==k);
            for(int c=1;c<=j;c++){
                dp[i][j]=max(dp[i][j],dp[i-c][j-c]+dp[i][c]);
            }
        }
    }
    cout<<dp[n][n];
	return 0;
}
