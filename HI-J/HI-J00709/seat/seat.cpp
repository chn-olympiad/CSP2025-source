#include<bits/stdc++.h>
using namespace std;
int a[110];//输入分数 
int b[110];//分配后座位一维 
int c[110];//从大到小分数 
int d[11][11];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;int lie=1;int r=0;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1);
	int e=1;
	for(int i=n*m+1;i>0;i--)
	{
		c[i]=a[e];
		e++;
	}
	int n1=n;
	for(int j=1;j<=n*m;j++)
	{
		
		if(lie==1)
		{
			b[j]=c[j];
		}
		else if(lie==0)
		{
			b[j]=c[j+n1-1];
			n1-=2;
		}
		if(j%n==0)
		{
			if(lie==1)
			{
				lie=0;
			}
			else
			{
				lie=1;
			}
		}
	}
	int cnt;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			d[i][j]=b[cnt];
			cnt++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(d[i][j]==r)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
}
