#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxn=505;
char c1[maxn];
int c[maxn];
int a[maxn];
int sum1=0,sum0=0;
long long sum=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>c1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		c[i+1]=c1[i]-'0';
		if(c[i+1]==1)
		{
			sum1++;
		}
		else
		{
			sum0++;
		}
	}
	if(m==1||sum1==n)
	{
		sum=1;
        for(int i=1;i<=n;i++)
        {
        	sum*=n;
        	sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
    else if((m==n&&sum1!=n)||(sum1<m))
	{
		cout<<0;
		return 0;
	}
	else
	{
		int sum=1;
		for(int i=1;i<=m;i++)
		{
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
