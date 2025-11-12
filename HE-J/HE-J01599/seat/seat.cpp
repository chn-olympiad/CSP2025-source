#include<bits/stdc++.h>
using namespace std;
int n,m,seat[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>seat[i];
	}
	int R=seat[0];
	sort(seat,seat+n*m,cmp);
	for(int i=0;i<n*m;i++)
	{
		if(seat[i]==R)
		{
			int c,r;
			c=(i+2)/n;
			if(c&1)
			{
				r=1+i%n;
			}
			else
			{
				r=n-i%n;
			}
			cout<<c<<' '<<r;
			break;
		}
	}
	return 0;
}
