#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
int n,m;
int a[105],dx[]={1,-1,0},dy[]={0,0,1};
int b[15][15];

struct node
{
	int i,j;
};
queue <node>q;
bool cmp(int a,int b)
{
	return a>b;
}
int cnt=0;
void bfs(int a1)
{
	q.push({1,1});
	
	b[1][1]=a[++cnt];
	
	
	while(!q.empty())
	{
		cnt++;
		
		for(int i=0;i<=2;i++)
		{
			int x=q.front().i+dx[i],y=q.front().j+dy[i];
			if(x>n||y>m||x<=0||y<=0)continue;
			if(b[x][y])continue;
			q.push({x,y});
			b[x][y]=a[cnt];
			
			q.pop();
			i=3;
		}
		if(a[cnt]==a1)
		{
			cout<<q.front().j<<" "<<q.front().i;
			exit(0);
		}
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int a1=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a1==a[1])
	{
		cout<<1<<" "<<1;
		return 0;
	}
	
	
	bfs(a1);
	return 0;
}
