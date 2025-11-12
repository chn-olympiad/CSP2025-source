#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500105],s[500105],dp[500105];
vector<int> v[1100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	v[0].push_back(0);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1];
		int val=s[i]^k;
		for(int j=0;j<v[val].size();j++){
			dp[i]=max(dp[i],dp[v[val][j]]+1);
		}
		v[s[i]].push_back(i);
	}
	cout<<dp[n];
	return 0;
} 
