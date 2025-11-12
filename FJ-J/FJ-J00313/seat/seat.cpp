#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],p=1,k=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	{		
		scanf("%d",&a[i]);
	}
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1]) p++;
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==1)
		for(int j=1;j<=n;j++)
		{
			k++;
			if(k==p)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
		else
		for(int j=n;j>0;j--)
		{
			k++;
			if(k==p)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
}
