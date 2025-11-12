#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500005];
int sum;
int dp[500005];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=0;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		sum=(sum^a[i]);
		int t1=(sum^k);
		dp[i]=dp[i-1];
		if(t1==0||mp[t1]!=0){
			dp[i]=max(dp[i],dp[mp[t1]]+1);
		}
		mp[sum]=i;
	}
	cout<<dp[n];
	return 0;
}
