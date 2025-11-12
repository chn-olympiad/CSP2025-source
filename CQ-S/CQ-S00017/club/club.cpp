#include<bits/stdc++.h>
#define N 100010
using namespace std;

struct node
{
	int y,z,c,id;
};

struct node2
{
	int x,I,J;
}a[100010];

bool cmp(node2 a,node2 b)
{
	return a.x>b.x;
}

vector <node> v[N];
int dis[N],vis[N],now[N],cnt[N],t,n,ans;
queue <int> q;

void add(int x,int y,int z,int c)
{
	v[x].push_back({y,z,c,v[y].size()});
	v[y].push_back({x,0,-c,v[x].size()-1});
}

int bfs()
{
	for(int i=0;i<=n+4;i++) dis[i]=-2e9;
	memset(now,0,sizeof(now));
	dis[0]=0;
	vis[0]=1;
	q.push(0);
	while(!q.empty())
	{
		int x=q.front();
		vis[x]=0;
		q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i].y,z=v[x][i].z,c=v[x][i].c;
			if(z<=0) continue;
			if(dis[x]+c>dis[y])
			{
				dis[y]=dis[x]+c;
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
	return dis[n+4]!=-2e9;
}

int dfs(int x,int sum)
{
	if(x==n+4) return sum;
	vis[x]=1;
	int res=0;
	for(int i=now[x];i<v[x].size();i++)
	{
		now[x]=i;
		int y=v[x][i].y,z=v[x][i].z,c=v[x][i].c,id=v[x][i].id;
		if(z<=0||vis[y]||dis[x]+c!=dis[y]) continue;
		int k=dfs(y,min(sum,z));
		v[x][i].z-=k,v[y][id].z+=k;
		sum-=k,res+=k,ans+=k*c;
		if(sum<=0) break;
	}
	vis[x]=0;
	return res;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=1000)
		{
			for(int i=1;i<=n;i++) 
			{
				int x,y,z;
				cin>>x>>y>>z;
				add(0,i,1,0);
				add(i,n+1,1,x);
				add(i,n+2,1,y);
				add(i,n+3,1,z);
			}
			add(n+1,n+4,n/2,0);
			add(n+2,n+4,n/2,0);
			add(n+3,n+4,n/2,0);
			ans=0;
			while(bfs()) dfs(0,2e9);
			cout<<ans<<endl;
			for(int i=0;i<=n+4;i++) v[i].clear();
		}
		else
		{
			ans=0;
			int m=0;
			memset(vis,0,sizeof(vis));
			memset(cnt,0,sizeof(cnt));
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=3;j++)
				{
					int x;
					scanf("%d",&x);
					a[++m]={x,i,j};
				} 
			}
			sort(a+1,a+m+1,cmp);
			for(int i=1;i<=m;i++)
			{
				int x=a[i].x,I=a[i].I,J=a[i].J;
				if(vis[I]||cnt[J]==n/2) continue;
				vis[I]=1,cnt[J]++,ans+=x;
			}
			printf("%d\n",ans);
		}
	}
} 
