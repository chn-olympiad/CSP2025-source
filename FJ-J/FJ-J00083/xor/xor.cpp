#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	long long k;
	int cc = 0;
	cin>>n>>k;
	bool flag  = 1;
	bool flag2 = 1;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag = 0;
		}
		if(a[i]!=1&&a[i]!=0){
			flag2 = 0;
			
		}
		if(a[i] ==1){
			cc++;
		}
	}
	if(flag){
		int x = (int)n/2;
		cout<<x;
		return 0;
	}
	if(flag2&&k == 1){
		cout<<cc;
		return 0;
	}else if(flag2&&k == 0){
		cout<<(n-cc)+cc/2;
		return 0;
	}
	long long dp[n+5][n+5];
	for(int i = 1;i<=n;i++){
		dp[i][i] = a[i];
		for(int j = 1;j<i;j++){
			dp[i][j] = dp[i-1][j]^a[i];
		}
	}
	int cnt = 0;
	int j1 = 0;
//	for(int i = 1;i<=n;i++){
//		for(int j = 1;j<=i;j++){
//			cout<<dp[i][j];
//		}
//		cout<<endl;
//	}
	for(int i = 1;i<=n;i++){
		for(int j = j1+1;j<=i;j++){
			if(dp[i][j]==k){
				cnt++;
//				cout<<i<<" "<<j<<endl;
				j1 = j;
				break;
			}
//			cout<<dp[i][j]<<' ';
		}
//		cout<<endl;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

