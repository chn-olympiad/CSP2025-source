#include<bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int n,m,ai;
int find()
{
	int d=1;
	for(int i=1;i<=n*m;i++)
	{
		if(q.top()==ai)
		{
			return d;
		}
		else
		{
			q.pop();
			d++;
		}
	}
}
int gm(int x)
{
	if (x%2==0) return 2;
	else return 1;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>ai;
	q.push(ai);
	for(int i=1;i<=n*m-1;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	int xl=find();
	if(xl%n==0)
	{
		cout<<xl/n<<" "<<n;
	}
	else
	{
		int a=xl%n;
		if(gm(xl/n+1)==1)
		{
		cout<<xl/n+1<<" "<<a;
		}
		else
		{
			cout<<xl/n+1<<" "<<n-a+1;
		}
	}
	return 0;
}
