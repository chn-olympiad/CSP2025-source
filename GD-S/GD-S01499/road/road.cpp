#include<bits/stdc++.h>
#define int long long
#define pir pair<int,int>
using namespace std;
const int N=1e4+5;
int n,m,k,a[15][N],f[N],cnt[N],ans;
struct node{
	int u,v,w;
	bool operator <(const node uu)const{
		return w>uu.w;
	}
};
priority_queue<node>q;
map<int,int> dis;
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int get(int x,int y)
{
	return x*10000+y;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i,cnt[i]=1;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		if(dis[get(min(u,v),max(u,v))]==0)dis[get(min(u,v),max(u,v))]=w;
		else dis[get(min(u,v),max(u,v))]=min(dis[get(min(u,v),max(u,v))],w);
	}
	for(int i=1;i<=k;i++)
	{
		int w;
		cin>>w;
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			for(int u=1;u<j;u++)
			{
				if(dis[get(u,j)]==0)dis[get(u,j)]=w+a[i][j]+a[i][u];
				else dis[get(u,j)]=min(dis[get(u,j)],w+a[i][j]+a[i][u]);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			q.push({i,j,dis[get(i,j)]});
	while(!q.empty())
	{
		int u=q.top().u,v=q.top().v,w=q.top().w;
		q.pop();
		int fx=find(u),fy=find(v);
		if(fx!=fy)
		{
			ans+=w,f[fx]=fy;
//			cout<<w<<'\n';
			cnt[fy]+=cnt[fx],cnt[fx]=0;
			if(cnt[fy]==n)break;
		}
	}
	cout<<ans;
	return 0;
}

