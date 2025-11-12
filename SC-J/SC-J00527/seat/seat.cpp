#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int h=n*m;
	int c,r;
	int a[100];
	int lie[100][100];
	for(int i=1;i<=h;i++)
	cin>>a[i];
	int R=a[1];
	for(int i=h;i>0;i--)
	for(int j=h;j>0;j--)
	{
		if(a[j]<a[j-1])
		{
			int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(j!=n)
		continue;
		if(i%2!=0)
		{
			for(int x=h,f=1;x>=n;f++,x--)
			{
				lie[i][f]=a[x];
			}
		}
		if(i%2==0)
		{
			for(int x=1,f=1;x<=n;f++,x++)
			lie[i][f]=a[x];
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	{
		if(R==lie[i][j])
		c=i;r=j;
	}
	cout<<c<<" "<<r;
}