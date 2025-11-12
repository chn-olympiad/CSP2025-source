#include<bits/stdc++.h>
using namespace std;
int n,m,a[225],c[15][15],node,kol;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	node=a[1];
	sort(a+1,a+1+n*m,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(i%n==0)
		{
			kol=i-1;
		}
		else
		{
			kol=i;
		}
		if(kol/n%2==0)
		{
			if(i%n==0)
			{
				c[n][i/n]=a[i];
			}
			else
			{
				c[i%n][(i/n)+1]=a[i];
			}
		}
		else
		{
			if(i%n==0)
			{
				c[1][i/n]=a[i];
			}
			else
			{
				c[n-(i%n)+1][i/n+1]=a[i];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]==node)
			{
				cout<<j<<" "<<i;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
