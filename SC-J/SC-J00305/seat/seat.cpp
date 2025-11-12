#include<bits/stdc++.h>
using namespace std;
int a[1000];
int mp[100][100];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int temp,n,m;
	cin>>n>>m;
	temp=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				mp[i][j]=temp;
				temp++;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				mp[i][j]=temp;
				temp++;
			}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+1+m*n,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[mp[i][j]]==t)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}