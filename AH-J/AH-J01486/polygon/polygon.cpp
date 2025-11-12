#include<bits/stdc++.h>
using namespace std;
long long rst,n,a[5010];
map<vector<long long>,bool> dp[5010];
long long dfs(vector<long long> v)
{
	long long cnt=0,sum=0;
	for(long long j=0;j<v.size();j++)
	{
		sum+=a[v[j]];
	}
	for(long long i=n;i>v[v.size()-1];i--)
	{
		if(sum>a[i])
		{
			cnt+=i-v[v.size()-1];
			break;
		}
	}
	for(long long i=v[v.size()-1]+1;i<=n;i++)
	{
		vector<long long> vv(v);
		v.push_back(a[i]);
		cnt+=dfs(vv);
	}
	return cnt;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=3;i<=n;i++)
	{
		vector<long long> v;
		v.push_back(i);
		rst+=dfs(v);
	}
	cout<<rst%998244353;
	/*for(long long i=1;i<=n;i++)
	{
		for(long long j=i+1;j<=n;j++)
		{
			for(long long k=j+1;k<=n;k++)
			{
				if(a[i]+a[j]+a[k]>max(a[i],max(a[j],a[k])))
				{
					vector<long long> av;
					av.push_back(i);
					av.push_back(j);
					av.push_back(k);
					dp[3][av]=true;
				}
			}
		}
	}
	for(long long i2=4;i2<=n;i2++)
	{
		for(auto e:dp[i2-1])
		{
			for(long long i=e.first[e.first.size()-1]+1;i<=n;i++)
			{
				long long maxn2=a[i],sum2=a[i];
				for(long long j=0;j<e.first.size();j++)
				{
					maxn2=max(maxn2,a[e.first[j]]);
					sum2+=a[e.first[j]];
				}
				if(sum2>maxn2)
				{
					vector<long long> vvv=e.first;
					vvv.push_back(i);
					dp[i2][vvv]=true;
				}
			}
		}
	}
	for(long long i=3;i<=n;i++)
	{
		rst+=dp[i].size();
		rst%=998244353;
	}
	cout<<rst;*/
}
