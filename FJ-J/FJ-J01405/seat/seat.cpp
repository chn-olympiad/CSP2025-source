#include<bits/stdc++.h>
using namespace std;
priority_queue<int> q;
int s[105][105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int num=0;
	for(int i=1;i<=n*m;i++)
	{
		int a;
		cin>>a;
		if(i==1)
		{
			num=a;
		}
		q.push(a);
	} 
	int x,y;
	bool flag=false;
	for(int i=1;i<=m;i++)
	{
		int j;
		if(!q.empty())
		{
			for(j=1;j<=n;j++)
			{
				int p=q.top();
				q.pop();
				if(p==num)
				{
					flag=true;
					x=j;
					y=i;
					break;
				}
				s[j][i]=p;
			}
		}
		if(flag)
		{
			break;
		}
		if(!q.empty())
		{
			i++;
			j=n;
			for(j;j>=1;j--)
			{
				int p=q.top();
				q.pop();
				if(p==num)
				{
					x=j;
					y=i;
					flag=true;
					break;
				}
				s[j][i]=p;	
			}
		}
		if(flag)
		{
			break;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}
