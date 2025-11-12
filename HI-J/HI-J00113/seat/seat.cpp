#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[20][20];
int b[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	b[1]=r;
	for(int i=2;i<=n*m;i++)
	{
		cin>>b[i];
	}
	int k=1,p=1;
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(p==1)
		{
			for(int j=1;j<=n;j++)
			{
				a[j][i]=b[k];
				k++;
				p++;
			}
		}
		else
		{
			for(int j=n;j>=1;j--)
			{
				a[j][i]=b[k];
				k++;
				p--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==r)
			{
				cout<<j<<" "<<i;
				break;
			 } 
			  
		}
	}
	return 0;
}
