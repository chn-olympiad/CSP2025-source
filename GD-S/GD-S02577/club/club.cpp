#include<bits/stdc++.h>
#include<queue>
using namespace std;
int t,n,a[100001][4],b[4],d[4][50001],e[100001][4],sum;
queue<int> abc;
bool amp(int x,int y)
{
	return a[x][1]>a[y][1];
}
bool bmp(int x,int y)
{
	return a[x][2]>a[y][2];
}
bool cmp(int x,int y)
{
	return a[x][3]>a[y][3];
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			if(a[j][1]>a[j][2])
			{
				e[j][1]=1;
				e[j][2]=2;
				if(a[j][2]>a[j][3]) e[j][3]=3;
				else if(a[j][1]>a[j][3])
				{
					e[j][2]=3;
					e[j][3]=2;
				}
				else
				{
					e[j][1]=3;
					e[j][2]=1;
					e[j][3]=2;
				}
			}
			else
			{
				e[j][1]=2;
				e[j][2]=1;
				if(a[j][1]>a[j][3]) e[j][3]=3;
				else if(a[j][2]>a[j][3])
				{
					e[j][2]=3;
					e[j][3]=1;
				}
				else
				{
					e[j][1]=3;
					e[j][2]=2;
					e[j][3]=1;
				}
			}
			abc.push(j);
		}
		while(!abc.empty())
		{
			for(int j=1;j<=3;j++)
			{
				if(b[e[abc.front()][j]]<(n/2))
				{
					sum+=a[abc.front()][e[abc.front()][j]];
					if(a[abc.front()][e[abc.front()][j]]<a[d[e[abc.front()][j]][b[e[abc.front()][j]]]][e[abc.front()][j]])
					{
						b[e[abc.front()][j]]++;
						d[e[abc.front()][j]][b[e[abc.front()][j]]]=abc.front();
					}
					else
					{
						b[e[abc.front()][j]]++;
						d[e[abc.front()][j]][b[e[abc.front()][j]]]=abc.front();
						if(e[abc.front()][j]==1) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][j]]+b[e[abc.front()][j]]+1,amp);
						if(e[abc.front()][j]==2) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][j]]+b[e[abc.front()][j]]+1,bmp);
						if(e[abc.front()][j]==3) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][j]]+b[e[abc.front()][j]]+1,cmp);
					}
					break;
				}
				else
				{
					if(a[abc.front()][e[abc.front()][j]]>a[d[e[abc.front()][j]][b[e[abc.front()][j]]]][e[abc.front()][j]])
					{
						abc.push(d[e[abc.front()][j]][b[e[abc.front()][j]]]);
						sum-=a[d[e[abc.front()][j]][b[e[abc.front()][j]]]][e[abc.front()][j]];
						sum+=a[abc.front()][e[abc.front()][j]];
						if(a[abc.front()][e[abc.front()][j]]<a[d[e[abc.front()][j]][b[e[abc.front()][j]]]][e[abc.front()][j]])
						{
							b[e[abc.front()][j]]++;
							d[e[abc.front()][j]][b[e[abc.front()][j]]]=abc.front();
						}
						else
						{
							b[e[abc.front()][j]]++;
							d[e[abc.front()][j]][b[e[abc.front()][j]]]=abc.front();
							if(e[abc.front()][j]==1) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][i]]+b[e[abc.front()][j]]+1,amp);
							if(e[abc.front()][j]==2) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][i]]+b[e[abc.front()][j]]+1,bmp);
							if(e[abc.front()][j]==3) sort(d[e[abc.front()][j]]+1,d[e[abc.front()][i]]+b[e[abc.front()][j]]+1,cmp);
						}
						break;
					}
				}
			}
			abc.pop();
		}
		cout<<sum<<endl;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(d,0,sizeof(d));
		memset(e,0,sizeof(e));
		sum=0;
		n=0;
	}
 } 
