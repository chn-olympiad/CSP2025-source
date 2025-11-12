#include<bits/stdc++.h>
#include<cstdio> 
using namespace std;
int a[15][15];
int q[100005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int w=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			q[w]=a[i][j];
			w++;
		 } 
	}
	w--;
	sort(q+1,q+1+w);
	int x=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(w!=0)
			{
				a[i][j]=q[w];
				w--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i%2==0)
			{
				for(int k=1;k<=m;k++)
				{
					if(a[i][j]>a[i][j+1] && a[i][j+1]!=0 && a[i][j]!=0)
					{
						swap(a[i][j],a[i][j+1]);
					}
				}
			}
		} 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==x)
			{
				cout<<i<<" "<<j;
			}
		}
	}
	return 0;
} 
