#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int n,m,a[1010],num=0,ans=0,b[1010][1010],sum=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			ans=a[i];
		}
	}
	sort(a+1,a+sum+1,cmp);
	sum=1;
	while(num<m)
	{
		num++;
		if(num%2!=0)
		{
			for(int i=1;i<=n;i++)
			{
				b[i][num]=a[sum];
				sum++;
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				b[i][num]=a[sum];
				sum++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(ans==b[i][j])
			{
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
