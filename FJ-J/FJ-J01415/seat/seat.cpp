#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[106];
int n,m,c,r;

bool p(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a;
	for(int i=1;i<=n*m;i++)
	{
		cin>>b[i];
		a=i;
	}
	int s=b[1];
	sort(b+1,b+a,p);
	
	int d=0;
	
	for(int j=1;j<=a;j++)
	{
		if(b[a]==s)
		{
			d=j;
		}
	}
	
	for(int j=1;d-n*j>=n;j++)
	{
		r=j;
		c=d-n*(j-1);
	}
	cout<<c<<r;
	return 0;
 } 
