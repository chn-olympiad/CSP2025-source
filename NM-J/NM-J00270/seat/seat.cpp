#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[2009];
int p[209][209];
int l,c;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+m*n,greater<int>());
	for(int j=1;j<=m;j++)
	{
		if(j%2==0) 
		{
			for(int i=n;i>=1;i--)
			{
				l++;
				p[j][i]=a[l];
			}
			
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				l++;
				p[j][i]=a[l];
			}
		}
		
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(p[j][i]==c) 
			{
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
