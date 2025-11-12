#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],dp[N],s[N];
int n,k;
vector<int> v[1050005];
int main()
{
	freopen("xor6.in","r",stdin);
	//freopen("xor.out","w",stdout);
	cin>>n>>k;
	v[0].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
		v[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		int p=k^s[i];
		dp[i]=dp[i-1];
		if(v[p].size())
		{
			int l=0,r=v[p].size()-1;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(v[p][mid]<i)l=mid+1;
				else r=mid;
			}
			if(v[p][l]<i)dp[i]=max(dp[i],dp[v[p][l]]+1);
			else if(l>0&&v[p][l-1]<i)dp[i]=max(dp[i],dp[v[p][l-1]]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
