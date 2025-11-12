#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans;
int a[500005],dp[500005];
map<int,vector<int>>mp; 
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	mp[0].push_back(0);
	for(int i=1;i<=n;++i){
		dp[i]=dp[i-1];
		int p=a[i]^k;
		if(mp[p].size()){
			for(int j:mp[p]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		mp[a[i]].push_back(i);
	}
	cout<<dp[n];
}
