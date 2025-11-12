#include<bits/stdc++.h>
using namespace std;
int n,k,s[500005],p[500005],dp[500005],ans;
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	p[1]=s[1];
	mp[p[1]]=1;
	if(s[1]==k)dp[1]+=1;
	ans=max(ans,dp[1]);
	for(int i=2;i<=n;i++){
		p[i]=p[i-1]^s[i];
		dp[i]=dp[i-1];
		if(s[i]==k)dp[i]+=1;
		if(p[i]==k)dp[i]=max(dp[i],1);
		if(mp[p[i]^k])dp[i]=max(dp[i],dp[mp[p[i]^k]]+1);
		mp[p[i]]=i;
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
