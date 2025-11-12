#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int a[N],pre[N];
int dp[N],mx[N];
vector<int>w[M];
int findk(int i,int p)
{
	int l=0,r=w[p].size()-1;
	if(r<0)return -1;
	int ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(w[p][mid]>i)r=mid-1;
		else ans=mid,l=mid+1;
//		cout<<l<<" "<<r<<'\n'; 
	}
//	cout<<ans<<" ";
	if(w[p][ans]>i)return -1;
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,k;
	cin>>n>>k;
	w[0].push_back(0);
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		pre[i]=a[i]^pre[i-1];
		w[pre[i]].push_back(i);
//		cout<<pre[i]<<" ";
	}
	memset(dp,128,sizeof dp);
	dp[0]=0;
	for(int i=1; i<=n; i++) {
		int p=k^pre[i];
		int j=findk(i,p);
//		cout<<w[p][j]<<'\n';
		if(j==-1)dp[i]=0;
		else if(w[p][j]==i)
		{
			if(j>=1)dp[i]=max(dp[w[p][j-1]]+1,dp[i]);
			if(k!=0)dp[i]=max(dp[i-1]+1,dp[i]);
		}
		else dp[i]=dp[w[p][j]]+1;
		
		dp[i]=max(dp[i],dp[i-1]);
//		cout<<dp[i]<<" ";
	}
	cout<<dp[n];
	return 0;
}
