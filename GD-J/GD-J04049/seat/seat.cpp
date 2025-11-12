#include<bits/stdc++.h>
using namespace std;
int a[30][30];
priority_queue<int> q;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;
			scanf("%d",&x);
			q.push(x);
			if(i==1&&j==1)
			{
				z=x;
			}
		}
	}
	int i=0,j=1;
	while(true)
	{
		if(j%2==1)
		{
			i++;
			if(q.top()==z)
			{
				cout<<j<<" "<<i;
				break;
			}
			q.pop();
			if(i==n)
			{
				j++;	
				i++;
			}	
		}	
		else
		{
			i--;
			if(q.top()==z)
			{
				cout<<j<<" "<<i;
				break;
			}
			q.pop();
			if(i==1)
			{
				j++;
				i--;
			}
		}
	} 
	return 0;
}
