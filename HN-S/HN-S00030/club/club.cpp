#include<bits/stdc++.h>
using namespace std;
int t;
long long sum=0;
int b[4];
bool w[4]={0};
long long init(int n)
{
	long long a[100005][4]={0};
	sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		long long maxx=0;
		for(int j=1;j<=3;j++)
		{
			maxx=max(a[i][j],maxx);
		}
		for(int j=1;j<=3;j++)
		{
			if(w[j]==true) continue;
			if(maxx==a[i][j])
			{
				if(b[j]<n/2)
				{
					sum+=maxx;
					b[j]++;
					continue;
				}
				else
				{
					w[j]=true;
				}
			}
		}
	}
	return sum;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long n;
		cin>>n;
		cout<<init(n);
	}
	return 0;
}
