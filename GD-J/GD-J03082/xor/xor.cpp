#include<bits/stdc++.h>
using namespace std;
long long yhh(int a[],int n,int be){
	long long s=a[be];
	for(int i=be+1;i<=n;i++){
		s^=a[i];
	}
	return s;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int b[n];
	vector < long long > dp(n+1,0);
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		dp[i] = (b[i-1]==k?1:0);
		for(int j=0;j<i;j++){
			dp[i] = max(dp[i],dp[j]+(yhh(b,i-1,j)==k?1:0));
		}
	}
	cout<<dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
