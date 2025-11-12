#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5,MAXM=1e6+5,INF=0x3f3f3f3f,MAXK=15;
#define int long long
struct Edge
{
	int to,w,nxt;
}edge[(MAXM*MAXK)<<1];
int head[(MAXM*MAXK)<<1],cnt;

int vis[MAXN+MAXK],dis[MAXN+MAXK],us[MAXK],op[MAXK];

void init()
{
	for(int i=0;i<((MAXM*MAXK)<<1);i++)
	{
		head[i]=-1;
		edge[i].nxt=-1;
	}
	cnt=0;
}
void add(int u,int v,int w)
{
	edge[cnt].to=v;
	edge[cnt].w=w;
	edge[cnt].nxt=head[u];
	head[u]=(cnt++);
}
int n,m,k,ans=INF;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
void init_p()
{
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
}
void prim()
{
	dis[1]=0;
	q.push(make_pair(dis[1],1));
	while(!q.empty())
	{
		pair<int,int> x=q.top();
		q.pop();
		if(vis[x.second]==1)
			continue;
		vis[x.second]=1;
		for(int i=head[x.second];~i;i=edge[i].nxt)
		{
			if((vis[edge[i].to]==1)||((edge[i].to>n)?(us[edge[i].to-n]==0):0))
				continue;
			dis[edge[i].to]=min(dis[edge[i].to],edge[i].w);
			q.push(make_pair(dis[edge[i].to],edge[i].to));
		}
	}
}
void solve(int p)
{
	for(int i=0;i<=1;i++)
	{
		us[p]=i;
		if(p<k)
		{
			solve(p+1);
			continue;
		}
		//
//		cout<<endl;
//		for(int j=1;j<=k;j++)
//			cout<<us[j]<<" ";
//		cout<<endl;
		//
		int res=0;
		init_p();
		prim();
		for(int i=1;i<=n+k;i++)
		{
			//
//			cout<<dis[i]<<endl;
			//
			if((i>n)?(us[i-m]==0):0)
				continue;
			if(dis[i]==INF)
				break;
			res+=dis[i];
		}
		for(int j=1;j<=k;j++)
			if(us[j]==1)
				res+=op[j];
		ans=min(ans,res);
		//
//		cout<<res<<" "<<ans<<endl;
		//
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	init();
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++)
	{
		cin>>w;
		op[i]=w;
		for(int j=1;j<=n;j++)
		{
			cin>>w;
			add((i+n),j,w);
			add(j,(i+n),w);
		}
	}
	//
//	cout<<endl;
//	for(int i=1;i<=n+k;i++)
//	{
//		cout<<"//head["<<i<<"]: ";
//		for(int j=head[i];~j;j=edge[j].nxt)
//			cout<<"->(to: "<<edge[j].to<<" ,w: "<<edge[j].w<<")";
//		cout<<endl;
//	}
//	cout<<endl;
//	for(int i=1;i<=k;i++)
//		cout<<op[i]<<" ";
//	cout<<endl;
	//
	solve(1);
	cout<<ans;
	return 0;
}

/*
5 5 2
1 2 3
2 5 1
2 3 4
3 4 9
5 4 2
*/

/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
