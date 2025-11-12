#include<bits/stdc++.h>
using namespace std;
struct qujian{
	long long left;
	long long right;
};
vector<qujian> v;
long long n,k,ans;
long long a[500005],dp[500005];
bool cmp(qujian x,qujian y)
{
	if((x.right-x.left+1)==(y.right-y.left+1))
	{
		if(x.left==y.left)
		{
			return x.right<y.right;
		}
		return x.left<y.left;
	}
	return (x.right-x.left+1)<(y.right-y.left+1);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ts=1;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			ts=0;
		}
	}
	if(ts==1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1)
			{
				sum++;
			}
		}
		cout<<sum;
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		long long cnt=0;
		for(long long j=i;j<=n;j++)
		{
			cnt^=a[j];
			if(cnt==k)
			{
				v.push_back({i,j});
			}
		}
	}
	long long len=v.size();
	if(len==0)
	{
		cout<<0;
		return 0;
	}
	sort(v.begin(),v.end(),cmp);
	dp[0]=1;
	for(long long i=1;i<len;i++)
	{
		qujian tmp=v[i];
		dp[i]=1;
		long long maxf=0;
		for(long long j=0;j<i;j++)
		{
			if(dp[j]>maxf&&v[j].right<v[i].left)
			{
				maxf=dp[j];
			}
		}
		dp[i]+=maxf;
	}
	long long ans=0;
	for(long long i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
