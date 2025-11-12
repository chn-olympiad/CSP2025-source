#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],s[N],dp[N];
map<int,int> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	mp[0]=0;
	for(int i=1;i<=n;i++){
		int t=mp[s[i]^k];
		if(t==0&&(s[i]^k)) dp[i]=dp[i-1];
		else dp[i]=max(dp[i-1],dp[t]+1);
		mp[s[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
