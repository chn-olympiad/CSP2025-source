#include <bits/stdc++.h>
using namespace std;
int n,m,q=1,b;
int p[10000];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>p[1];
	b=p[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>p[i];
	}
	sort(p+1,p+1+n*m,cmp);
	for(int y=1;y<=m;y++)
	{
		if(y%2==1)
		{
			for(int x=1;x<=n;x++)
			{
				if(p[q]==b) 
				{
					cout<<y<<" "<<x;
					return 0;
				}
				q++;
			}
		}
		else 
		{
			for(int x=n;x>=1;x--)
			{
				if(p[q]==b)
				{
					cout<<y<<" "<<x;
					return 0;
				}
				q++;
			}
		}
	}
	return 0;
}
