#include<bits/stdc++.h>
using namespace std;
int jc(int a)
{
	int ret=1;
	for(int i=2;i<=a;i++)
	{
		ret*=i;
	}
	return ret;
}
int c(int a,int b)
{
	return jc(b)/(jc(b-a)*b);
}
long long n,a[5010],maxn=-1,tot;
const int N=998244353;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tot+=a[i];
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	if(n==3)
	{
		if(tot>2*maxn)
		{
			cout<<1;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	else
	{
		sort(a+1,a+n+1);
		unique(a+1,a+n+1);
		int k;
		for(int i=n;i>=1;i--)
		{
			if(a[i]==maxn)
			{
				k=i;
				i=1;	
			}
		}
		int ans=0;
		for(int i=3;i<=k;i++)
		{
			ans+=c(i,k)%N;
		}
		cout<<ans%N;
		return 0;
	}
	return 0;
}