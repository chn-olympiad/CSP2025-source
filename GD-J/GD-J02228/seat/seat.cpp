#include <bits/stdc++.h>
using namespace std;
struct node
{
	int id,num;
}a[105];
queue<node> q;

bool cmp(node x, node y)
{
	return x.num>y.num;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1; i<=n*m; i++)
	{
		q.push({a[i].id,a[i].num});
	}
	for(int j=1; j<=m; j++)
	{
		if(j%2==1)
		{
			for(int i=1; i<=n; i++)
			{
				if(q.front().id==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				q.pop();
			}
		}
		else
		{
			for(int i=n; i>=1; i--)
			{
				if(q.front().id==1)
				{
					cout<<j<<" "<<i;
					return 0;
				}
				q.pop();
			}
		}
	}
	return 0;
} 
