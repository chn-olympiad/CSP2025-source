#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[5001];
int dp[5001][4];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n==3){
		int a1,b1,c1;
		cin>>a1>>b1>>c1;
		if(a1+b1>c1&&b1+c1>a1&&a1+c1>b1){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	else if(n<3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dp[i][0]=dp[i-1][1]%998244353;
		
	}
	cout<<(dp[n][1]+dp[n][0])%998244353;
	return 0;
}