#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
long long int a[5010],cnt[5010],ans=0,n;
void DFS(int t,int maxn,int sum,int cnt)
{
	if(t>n)
	{
		if(sum>2*maxn&&cnt>=3)
		{
			ans++;
		}
		return;
	}
	if(n-t<2-cnt)
	{
		return;
	}
	DFS(t+1,maxn,sum,cnt);
	DFS(t+1,a[t],sum+a[t],cnt+1);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=30)
	{
		DFS(1,0,0,0);
		cout<<ans;
		return 0;
	}
	long long int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>=a[i-1];j--)
		{
			cnt[j]+=cnt[j-a[i-1]];
			cnt[j]%=N;
		}
	}
	for(int i=0;i<=a[n];i++)
	{
		sum+=cnt[i];
		sum%=N;
	}
	for(long long int i=3;i<=n;i++)
	{
		long long sum1=1,sum2=1,k=min(i,n-i);
		for(int j=n;j>=n-k;j--)
		{
			sum1*=j;
			sum1%=N;
		}
		for(int j=1;j<=k;j++)
		{
			sum2*=j;
			sum2%=N;
		}
		ans+=sum1/sum2;
		ans%=N;
	}
	cout<<ans-sum;
	return 0;
}
