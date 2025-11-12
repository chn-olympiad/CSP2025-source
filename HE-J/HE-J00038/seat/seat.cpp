#include<bits/stdc++.h>
using namespace std;
int b[13][3],a[104],c,r,al,all;
int f(int x,int y)
{
	return x>y;
	
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++)
	{
		cin>>a[i];	
	}
	al=a[1];
	sort(a+1,a+m*n+1,f);
	for(int i=1;i<=n;i++)
	{
		b[i][1]=a[i];
	}
	int s=n;
	for(int i=n;i>=1;i--)
	{
		b[i][2]=a[s+1];
		s++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=2;j++)
		{
			if(b[i][j]==al)
			{
				cout<<j<<' '<<i;
				
			}
		}
	}
	return 0;
}
