#include<bits/stdc++.h>
using namespace std;
long long n,m,a1,t,s=1,ans1,ans2;
priority_queue<long long,vector<long long>,less<long long> > q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>a1;
	q.push(a1);
	for(int i=1;i<n*m;i++)
	{
		cin>>t;
		q.push(t);
	}
	while(!q.empty())
	{
		if(q.top()==a1)
		{
			break;
		}
		q.pop();
		s++;
	}
	if(s%n)
	ans1=s/n+1;
	else
	ans1=s/n;
	if(ans1%2)
	{
		if(s%n)
		ans2=s%n;
		else
		ans2=n;
	}
	else
	{
		if(s%n)
		ans2=n-s%n+1;
		else
		ans2=1;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
}
