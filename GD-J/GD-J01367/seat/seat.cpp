#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int p[11][11];
struct wei{
	int s;
	int b;
}a[101];
bool x(wei d,wei e)
{
	return d.b>e.b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].b;
	a[1].s=1;
	sort(a+1,a+1+n*m,x);
	int c=0;
	for(int i=1;i<=n/2+1;i++)
	{
		if(i*2-1<=n)
			for(int j=1;j<=m;j++)
			{
				c++;
				p[i*2-1][j]=a[c].b;
				if(a[c].s==1)
				{
					cout<<i*2-1<<" "<<j;
					return 0;
				}
			}
		if(i*2<=n)
			for(int j=m;j>=1;j--)
			{
				c++;
				p[i*2][j]=a[c].b;
				if(a[c].s==1)
				{
					cout<<i*2<<" "<<j;
					return 0;
				}
			}
	}
	return 0;
} 
//beng huai xing qiong tie dao 118496512 
//I like CCF
//Thank CCF 
