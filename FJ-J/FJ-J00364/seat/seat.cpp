#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[300],x,k=0;
bool cmp(int p,int q)
{
	return q<p;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
			cin>>b[i];
	x=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
			for(int i=1;i<=n;i++)
			{
				if(b[++k]==x)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
		else
			for(int i=n;i>=1;i--)
			{
				if(b[++k]==x)
				{
					cout<<j<<' '<<i;
					return 0;
				}
			}
	}
	return 0;
}
