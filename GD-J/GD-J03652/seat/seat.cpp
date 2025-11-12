#include<bits/stdc++.h>
using namespace std;
int n,m,b[10005],c[10005],ans=1,cnt;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
	}
	cnt=b[1];
	sort(b+1,b+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		c[i]=b[m*n-i+1];
	}
	for(int i=1;i<=n;i++)//iÁÐ 
	{
		for(int j=1;j<=m&&i%2==1;j++)//jÐÐ 
		{
			if(c[ans]==cnt)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			ans++;
		}
		for(int j=m;j>=1&&i%2==0;j--)
		{
			if(c[ans]==cnt)
			{
				cout<<i<<' '<<j;
				return 0;
			}
			ans++;
		}
	}
	return 0;
}
