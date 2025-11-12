#include<bits/stdc++.h>
using namespace std;
long long dp[1111];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
		cin>>n>>m;
		dp[3]=6;
		for(int i=4;i<=n;i++){
		dp[i]=dp[i-1]*n;
		}
		int y=998244353;
		cout<<abs(dp[n]%y);
		return 0;
	}
