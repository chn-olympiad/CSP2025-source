#include<bits/stdc++.h>
using namespace std;
int a[100005];
int mp[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int little_r=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int k=n*m;
	for(int i=1;i<=n;i++) //lie
	{
		if(i%2==0)
		{
			for(int j=m;j>=1;j--)
			{
				mp[j][i]=a[k];
				k--;
			}
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				mp[j][i]=a[k];
				k--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==little_r)
			{
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
