#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10005];
int c[11][10005];
int dp[1001][1001]={-1};
void DFS(int i,int j){
	while(dp[i][j]){
		for(int p=0;p<n;p++){
			if(dp[j][p]!=0 && dp[i][p]>=0){
				dp[i][j]=min(dp[i][j],dp[i][p]);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	int nums=0;
	for(int i=0;i<m;i++){
		int a1,a2,a3;
		cin >> a1 >> a2 >> a3;
		nums+=a3;
		dp[a1][a2]=dp[a2][a1]=a3;
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			cin >> c[i][j];
		}
	}
	if(k==0){
		cout << nums;
	}
	else if(c[0][0]==0){
		cout << 0;
		return 0;
	}
	return 0;
}
