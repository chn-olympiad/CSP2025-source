#include<bits/stdc++.h>
using namespace std;
int n,m,a;
priority_queue<pair<int,int> > q;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin)	
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a;
		if(i==1) 
		{
			q.push(make_pair(a,1));
			continue;
		}
		q.push(make_pair(a,0));
	}
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(q.top().second==1)
				{
					cout<<j<<' '<<i;
					return 0;
				}
				q.pop();
			}
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				if(q.top().second==1)
				{
					cout<<j<<' '<<i;
					return 0;
				}
				q.pop();
			}
		}
	}
	return 0;
}