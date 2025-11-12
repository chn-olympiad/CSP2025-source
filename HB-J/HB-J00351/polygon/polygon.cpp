#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],sum,maxt,sum_1,amax;
void tt(int cs,int t)
{
	if(cs==t)
	{
		if(sum_1>a[t])
		{
			sum+=1;
		}
		return;
	}
	sum_1+=a[cs];
	tt(cs+1,t);
	sum_1-=a[cs];
	tt(cs+1,t);
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
		amax=max(a[i],amax);
	}
	if(amax==1)
	{
		for(int i=3;i<=n;i++)
		{
			sum_1=1;
			for(int j=1;j<=i;j++)
			{
				sum_1=sum_1*(n+1-j)/j;
				sum_1%=998244353;
			}
			sum+=sum_1;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
	{
		sum_1=0;
		tt(1,i);
		sum%=998244353;
	}
	cout<<sum;
	return 0;
}
