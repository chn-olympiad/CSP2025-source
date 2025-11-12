#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,k;
int a[N],dp[N],sum[N];
vector<int> r[(1<<20)+5];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		r[sum[n]^sum[i-1]].push_back(i);
	}
	if(a[1]==k) dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1];
		if(r[k^sum[n]^sum[i]].size()==0) continue;
		int l=0,rr=r[k^sum[n]^sum[i]].size()-1;
		if(r[k^sum[n]^sum[i]][l]>=i) continue;
		while(l<rr)
		{
			int mid=(l+rr+1)>>1;
			if(r[k^sum[n]^sum[i]][mid]<=i) l=mid;
			if(r[k^sum[n]^sum[i]][mid]>i) rr=mid-1;
		}
		int id=l;
		if(r[k^sum[n]^sum[i]][id]>i) continue;
		dp[i]=max(dp[i],dp[r[k^sum[n]^sum[i]][id]-1]+1);
	}
	cout<<dp[n];
	return 0;
}
