#include<bits/stdc++.h>
using namespace std;
int m,n,a[100001],a1[100001],b[1000][1000],k=0,c=0,o=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a1[i];
	k=a1[1];
	sort(a1+1,a1+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		o++;
		a[o]=a1[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			c++;
			b[j][i]=a[c];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(b[i][j]==k)
			{
				if(j%2==0)cout<<j<<" "<<n-i+1;
				else cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
