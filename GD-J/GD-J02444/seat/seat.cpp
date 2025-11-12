#include <bits/stdc++.h>
#define long long int; 
using namespace std;
//const int N=1e6+10;
priority_queue<int> q;
int a[20][20];
int n,m;
int v;
int val[200];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>val[i];
		q.push(val[i]);
		
	}
	v=val[1];
	int j1=1;
	bool f=false;
	for(int i=1;i<=m;i++)
	{
		if(j1==1)
		{
			for(int j=j1;j<=n;j++)
			{
				if(q.top()==v)
				{
					cout<<i<<" "<<j;
					f=true;
					break;
				}
				//cout<<j<<" "<<i<<" "<<q.top()<<endl;
				a[j][i]=q.top();
				q.pop();
			}
			j1=n;
		}
		else if(j1==n)
		{
			for(int j=j1;j>=1;j--)
			{
				if(q.top()==v)
				{
					cout<<i<<" "<<j;
					f=true;
					break;
				}
				//cout<<j<<" "<<i<<" "<<q.top()<<endl;
				a[j][i]=q.top();
				q.pop();
			}
			j1=1;
		}
		if(f==true)
		{
			break;
		}
	}
	
	return 0;
}
