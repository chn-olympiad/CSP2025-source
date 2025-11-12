#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int t,n,club[4],a,b,c,member[4];
priority_queue<int,vector<int>,greater<int> > q[3];
void cho(int x,int y,int z)
{
	int m=max(x,max(y,z));
	if (x==m)
	{
		club[1]=x;
		club[2]=1;
		club[3]=x-max(y,z);
	}
	else if (y==m)
	{
		club[1]=y;
		club[2]=2;
		club[3]=y-max(x,z);
	}
	else
	{
		club[1]=z;
		club[2]=3;
		club[3]=z-max(x,y);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int i=1;i<=t;i++)
	{
		for (int j=1;j<=3;j++) member[j]=0;
		int tot=0;
		cin>>n;
		const int N=n/2;
		for (int j=1;j<=n;j++)
		{
			cin>>a>>b>>c;
			cho(a,b,c);
			if (member[club[2]]+1<=N)
			{
				member[club[2]]++;
				tot+=club[1];
				q[club[2]-1].push(club[3]);
			}
			else
			{
				if (q[club[2]-1].top()<club[3])
				{
					tot+=club[1]-q[club[2]-1].top();
					q[club[2]-1].pop();
					q[club[2]-1].push(club[3]);
				}
				else tot+=club[1]-club[3];	
			}
		}
		cout<<tot<<endl;
		for (int j=0;j<=2;j++)
		{
			while (!q[j].empty()) q[j].pop();
		} 
	}
	return 0;
}
