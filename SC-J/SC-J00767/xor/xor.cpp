#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum[500005],to[500005],dp[500005];
vector<int> a[1048626];
bool vis[500005];
int f(int x)
{
	if(x<=0)	return INT_MIN;
	if(x>n)	return 0;
	if(vis[x])	return dp[x];
	vis[x]=1;
	return dp[x]=max(f(x+1),f(to[x]+1)+1ll);
}
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int now;
		cin>>now;
		sum[i]=sum[i-1]^now;
		a[sum[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[m^sum[i-1]].size()==0)
		{
			to[i]=INT_MIN;
			continue;
		}
		int l=0,r=a[m^sum[i-1]].size()-1;
//		cout<<l<<" "<<r<<" ";
		while(l<r)
		{
			int mid=(l+r)/2;
			if(a[m^sum[i-1]][mid]>=i)	r=mid;
			else	l=mid+1;
		}
		if(a[m^sum[i-1]][l]>=i)	to[i]=a[m^sum[i-1]][l];
		else	to[i]=INT_MIN;
//		cout<<to[i]<<"\n";
	}
//	for(int i=1;i<=n;i++)	cout<<to[i]<<" ";
//	cout<<"\n";
	cout<<f(1)<<"\n";
	return 0;
}