#include<bits/stdc++.h>
using namespace std;
const int N=1e4+100,inf=2e9;
#define ll long long
int n,m,k,ww[11];
bool fx;
ll ans,dis[N],c[11];
bool vis[N],f[N];
struct node
{
	int x;ll w;
};
vector<node> v[N];
ll work(int p)
{
	ll s=0;
	for(int i=0;i<=n+k;i++) f[i]=0,dis[i]=2e9;
	for(int i=1;i<=k;i++)
	 if(!vis[n+i]) s+=c[i];
//	cout<<s<<endl;
	dis[1]=0;int e=1,j;f[1]=1;
	for(int i=1;i<p;i++)
	{
		for(auto to:v[e])
		{
			if(f[to.x]||vis[to.x]) continue;
			dis[to.x]=min(dis[to.x],to.w);
		}
		j=0;
		for(int to=1;to<=n+k;to++) 
		 if(dis[to]<dis[j]&&!f[to]&&!vis[to])
		  j=to;
		f[j]=1;s+=dis[j];dis[j]=0;e=j;
	} 
	return s;
}
void dfs(int p,int t)
{
	if(p>k)
	{
		return;
	}
	//cout<<p<<" "<<t<<" :1"<<endl;
	dfs(p+1,t);
	vis[ww[p]+n]=0;
	ll s=work(n+t+1);
	//cout<<p<<" "<<t<<" :2: "<<s<<endl;
	if(s<ans)
	{
		ans=s;
		dfs(p+1,t+1);
	}
	vis[ww[p]+n]=1;
	return;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1,x,y,w;i<=m;i++)
	{
		cin>>x>>y>>w;
		v[x].push_back((node){y,w});
		v[y].push_back((node){x,w});
	}
	for(int i=n+1;i<=n+k;i++)
	{
		cin>>c[i-n];
		bool ss=0;
		for(int j=1,w;j<=n;j++)
		{
			cin>>w;
			if(w) ss=1;
			v[i].push_back((node){j,w});
			v[j].push_back((node){i,w});
		}
		if(ss) fx=1;
	}
/*	if(!fx)
	{
		cout<<0;
		return 0;
	}*/
	srand(114514);
	for(int i=1;i<=k;i++)
	{
		//ww[i]=i;
		while(!ww[i])
		{
			int w=rand()%k+1;
		    for(int j=1;j<i;j++)
		     if(ww[j]==w) w=0;
		    ww[i]=w;
		}
	}
	for(int i=1;i<=k;i++) vis[i+n]=1;
	ans=work(n);
	dfs(1,0);
	cout<<ans;
	return 0;
} 
