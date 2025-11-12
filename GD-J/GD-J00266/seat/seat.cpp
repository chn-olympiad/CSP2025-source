#include<bits/stdc++.h>
using namespace std;
int n,m,x,a[105];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<m*n;i++)
	{
		cin>>a[i];
	}
	x=a[0];
	int b=1,c=1;
	sort(a,a+n*m,cmp);
	for(auto i : a)
	{
		if(i==x)
		{
			cout<<b<<' '<<c;
		}
		if(b%2==1)
		{
			c++;
		}
		else
		{
			c--;
		}
		if(c>n)
		{
			c=n;
			b++;
		}
		if(c<1)
		{
			c=1;
			b++;
		}
	}
	return 0;
}
