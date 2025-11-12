#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct Edge{
	int to,next_,val;
}edge[1000005];
int head[1000005],tot;
const long long inf=1e10+5;
void add(int x,int y,int val)
{
	edge[++tot].to=y;
	edge[tot].val=val;
	edge[tot].next_=head[x];
	head[x]=tot;
	return ;
}
queue<int> q;
bool flag[1000005];
long long ans[1000005];
long long dfs(int x)
{
	flag[x]=1;
	q.push(x);
	while(q.size())
	{
		int xx=q.front();
		flag[xx]=0;
		q.pop();
		for(int i=head[xx];i;i=edge[i].next_)
		{
			int y=edge[i].to;
			if(ans[y]>ans[xx]+edge[y].val)
			{
				ans[y]=ans[xx]+edge[i].val;
				//cout<<xx<<"->"<<y<<" "<<ans[y]<<"\n";
				if(flag[y]==0)
				{
					q.push(y);
					flag[y]=1;
				}
			}
		}
	}
	long long maxn=0;
	for(int i=1;i<=n;i++)
	{
		//cout<<ans[i]<<" ";
		maxn=max(maxn,ans[i]);
	} 
	return maxn;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k!=0) 
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,val;
		scanf("%d%d%d",&x,&y,&val);
		add(x,y,val);
		add(y,x,val);
	}
	for(int i=2;i<=n;i++) ans[i]=inf;
	printf("%lld",dfs(1));
	return 0;
} 