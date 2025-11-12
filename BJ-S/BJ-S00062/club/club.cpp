#include <bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int a1,a2,a3;
}a[200005];
int dp[205][205][205];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
		}
		for (int k=1;k<n;k++){
			for (int i=1;i<=k && i<=n/2;i++){
				for (int j=1;j<=k-i && j<=n/2;j++){
					dp[k+1][i+1][j]=max(dp[k+1][i+1][j],dp[k][i][j]+a[k].a1);
					dp[k+1][i][j+1]=max(dp[k+1][i][j+1],dp[k][i][j]+a[k].a2);
					dp[k+1][i][j]=max(dp[k+1][i][j],dp[k][i][j]+a[k].a3);
				}
			}
		}		
		int maxn=-1;
		for (int i=1;i<=n/2;i++){
			for (int j=1;j<=n/2;j++){
				maxn=max(maxn,dp[n][i][j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
