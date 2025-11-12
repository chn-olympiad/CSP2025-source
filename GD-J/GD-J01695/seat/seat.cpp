#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	priority_queue<int>q;
	int h;
	for(int i=1;i<=n*m;i++)
	{
		int a;
		cin>>a;
		if(i==1)
		{
			h=a;
		}
		q.push(a);
	}
	int p=1;
	while(!q.empty())
	{
		if(q.top()==h)
		{
			break;
		}
		else
		{
			p++;
			q.pop();
		}
	}
	int c,r;
	double cr=p,rc=n;
	c=ceil(cr/rc);
	int w=p%n;
	if(w==0)
	{
		if(c%2==0)
		{
			r=1;
			cout<<c<<" "<<r;
		}
		else
		{
			r=n;
			cout<<c<<" "<<r;
		}
	}
	else
	{
		if(c%2==0)
		{
			r=n-w+1;
			cout<<c<<" "<<r;
		}
		else
		{
			r=w;
			cout<<c<<" "<<r;
		}
	}
	return 0;
}
