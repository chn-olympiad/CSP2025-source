#include<bits/stdc++.h>
using namespace std;
long long ehh(long long x,long long y)
{
	queue<long long> a,b;
	stack<long long> c;
	while(x!=0)
	{
		int r=x%2;
		a.push(r);
		x=x/2;
	}
	while(y!=0)
	{
		int r=y%2;
		b.push(r);
		y=y/2;
	}
	while(!a.empty()&&!a.empty())
	{
		if(a.front()!=b.front())
		{
			c.push(1);
		}
		else
		{
			c.push(0);
		}
	}
	if(!a.empty())
	{
		while(!a.empty())
		{
			if(a.front()==0)
			{
				c.push(0);
			}
			else
			{
				c.push(1);
			}
		}
	}
	if(!b.empty())
	{
		while(!b.empty())
		{
			if(b.front()==0)
			{
				c.push(0);
			}
			else
			{
				c.push(1);
			}
		}
	}
	long long g;
	long long r=1;
	if(!c.empty())
	{
		while(!c.empty())
		{
			g=c.top()*g;
			r=r*2;
			c.pop();
		}
		return g;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long b=1^2;
	cout<<b;
}
