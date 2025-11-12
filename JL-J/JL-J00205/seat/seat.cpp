#include <bits/stdc++.h>
using namespace std;
#define N 15
priority_queue<long long> q;
long long zw[N][N];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n,m,t;
	bool ss=false;
	bool end=false;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		int temp;
		cin>>temp;
		if(i==1)
			t=temp;
		q.push(temp);
	}
	for(int j=1;j<=m;j++)
	{
		if(ss)
		{
			for(int i=n;i>=1;i--)
			{
				zw[i][j]=q.top();
				q.pop();
				if(zw[i][j]==t)
				{
					cout<<j<<' '<<i<<endl;
					//end=true;
					//break;
				}
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				zw[i][j]=q.top();
				q.pop();
				if(zw[i][j]==t)
				{
					cout<<j<<' '<<i<<endl;
					//end=true;
					//break;
				}
			}
		}
		ss=!ss;
		if(end)
			break;
	}
	
	return 0;
}
