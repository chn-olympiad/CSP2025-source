#include<bits/stdc++.h>
using namespace std;
long long a[100][100],n,m,num=1,ke;
struct sut
{
	long long num;
	char bj;
}shu[10000];
bool cmp(sut u,sut v)
{
	return u.num>v.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (long long i=1;i<=m;i++)
	{
		if (i%2==1)
		{
			for (long long j=1;j<=n;j++)
			{
				a[j][i]=num;
				num++;
			}
		}else
		{
			for (long long j=n;j>=1;j--)
			{
				a[j][i]=num;
				num++;
			}
		}
	}
	cin>>shu[1].num;
	shu[1].bj='R';
	for (long long i=2;i<=n*m;i++)
	{
		cin>>shu[i].num;
	}
	sort(shu+1,shu+1+n*m,cmp); 
	for (long long i=1;i<=n*m;i++)
	{
		if (shu[i].bj=='R')
		{
			ke=i;
		}
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=1;j<=m;j++)
		{
			if (a[i][j]==ke)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	return 0;
}
