#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
int n,m,flag,t;
priority_queue<int> q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int p;
		cin>>p;
		if(i==1)
		flag=p;
		q.push(p);
	}
	while(!q.empty())
	{
		t++;
		if(q.top()==flag)
		break;
		q.pop();
	}
	int s=t/n;
	int l=t%n;
	if(l>0)
	s++;
	if(s%2==1)
	{
		cout<<s<<" ";
		if(l==0)
		{
			cout<<n;
			return 0;
		}
		cout<<l;
	}
	else
	{
		cout<<s<<" ";
		if(l==0)
		{
			cout<<1;
			return 0;
		}
		cout<<n-l+1;
	}
	return 0;
}
