#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[100000];
int dp[100000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.in","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<m){
		cout<<0;
		return 0;
	}
	dp[0]=1;
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]*i;
	}
	cout<<dp[n];
	return 0;
}

