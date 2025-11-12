#include<bits/stdc++.h>
using namespace std;
const int _=1e6+5;
struct hp{
	int nxt,to,w;
}a[_*3];
//struct hp{
//	int u,v,w;
//}a[_*3];
int n,m,k,cnt=0,t[15][_],cnt2=0;
int h[_],ans;
bool b[_];
bool cmp(hp x,hp y)
{
	return x.w<y.w;
}
void add(int u,int v,int w)
{
	a[++cnt].w=w;
	a[cnt].to=v;
	a[cnt].nxt=h[u];
	h[u]=cnt;
}
void dfs(int x)
{
//	cout<<x<<endl;
	cnt2++;
	if(cnt2>=n) return;
	b[x]=1;
	int minn=INT_MAX,qwq=-1;
	for(int i=h[x];i;i=a[i].nxt)
	{
//		cout<<a[i].to<<" "<<a[i].w<<endl;
		if(b[a[i].to]==0&&minn>a[i].w)
		{
			minn=a[i].w;
			qwq=a[i].to;
		}
	}
	if(qwq>0)
	{
		ans+=minn;
		dfs(a[x].to);
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	memset(h,0,sizeof(h));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
//		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		int c;
		cin>>c;
		for(int j=1;j<=n;j++)
		{
			cin>>t[i][j];
		}
	}
//	sort(a+1,a+1+m,cmp);
	dfs(1);
//	for(int i=1;i<=n;i++) cout<<h[i]<<" ";
	cout<<ans<<endl;
	return 0;
}
