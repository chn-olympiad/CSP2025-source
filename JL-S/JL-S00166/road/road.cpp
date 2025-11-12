#include<bits/stdc++.h>
using namespace std;
#define N 100005
long long n,m;
int k,cnt=0,ans=0;
long long a[N],x[N];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=m;i++)
		{
		cin>>a[i];
	}
	cnt=k+m+1-i-2;
}
	for(int i=1;i<=cnt;i++)
	{
		cin>>a[i];
	}
	if(n<=10000&&m<=1000000&&k<=0)
	{
		for(int i=1;i<=n;i++)
		{
			while(i--)
			{
				a[i]++;
				n--;
				m--;
				k++;
				ans++;
				cout<<ans<<endl;
			}
		}
	}
	else if(n<=1000&&m<=100000&&k<=0)
	{
		for(int j=1;j<=n;j++)
		{
			while(j--)
			{
				a[j]++;
				n--;
				m--;
				k--;
				ans++;
				cout<<ans<<endl;
			}
		}
	}
	else if(n<=1000&&m<=1000000&&k<=10)
	{
		for(int i=1;i<=n;i++)
		{
			while(i--)
			{
				a[i]++;
				n++;
				m++;
				k--;
				ans++;
				cout<<ans<<endl;
			}
		}
	}
	else if(n<=10000&&m<=1000000&&k<=5)
	{
		for(int i=1;i<=n;i++)
		{
			while(i--)
			{
				a[i]++;
				n++;
				m++;
				k--;
				ans++;
				cout<<ans<<endl;
			}
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==0)  break;
			else
			cout<<ans<<endl;
		}
	}
	return 0;
}
