#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+7,M=5e7+7,MM=1e6+7;
const int INF=1e18;
int n,m,k;
int f[N],fa[N];
int val[17];
struct node
{
	int u,v,w;
}s[M],e[MM];
bool cmp(node x,node y){return x.w<y.w;}
int getNum(int u,int v){return (n-u+1+n-1)*(u-1)/2+(v-u);}
int find(int x)
{
	if(x==f[x]) return f[x];
	else return f[x]=find(f[x]);
}
int Find(int x)
{
	if(x==fa[x]) return fa[x];
	else return fa[x]=Find(fa[x]);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e[i].u=u,e[i].v=v,e[i].w=w;
		if(u>v) swap(u,v);
		int x=getNum(u,v);
		s[x].u=u,s[x].v=v,s[x].w=w;
	}
	sort(e+1,e+m+1,cmp);
	int vall=0;
	for(int i=1;i<=m;i++)
	{
//		cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].w<<"---+++\n";
		int u=Find(e[i].u),v=Find(e[i].v);
		if(u==v) continue;
		vall+=e[i].w;
		fa[u]=v;
	}
//	cout<<vall<<"--++-\n";
	
	for(int i=1;i<=k;i++)
	{
		cin>>val[i];
		if(val[i]>vall) break;
		for(int i=1;i<=n;i++) f[i]=i;
		vector<int> a(n+1);
		for(int j=1;j<=n;j++) cin>>a[j];
		for(int l=1;l<n;l++)
		{
			for(int r=l+1;r<=n;r++)
			{
				int x=getNum(l,r);
				s[x].u=l,s[x].v=r;
				if(!s[x].w) s[x].w=a[l]+a[r];
				else s[x].w=min(s[x].w,a[l]+a[r]);
			}
		}
		sort(s+1,s+n*(n-1)/2+1,cmp);
//		for(int i=1;i<=n*(n-1)/2;i++) cout<<s[i].u<<" "<<s[i].v<<" "<<s[i].w<<"++\n";
		int ans=0;
		for(int i=1;i<=n*(n-1)/2;i++)
		{
			int u=find(s[i].u),v=find(s[i].v);
			if(u==v) continue;
			ans+=s[i].w;
//			cout<<ans<<"+++\n";
			f[u]=v;
		}
		vall=min(vall,val[i]+ans);
//		cout<<ans<<"--\n";
	}
	cout<<vall;
		
	
//	int maxn=-INF;
//	for(int i=1;i<=m;i++)
//	{
//		int u=find(s[i].u),v=find(s[i].v);
//		if(u==v) continue;
//		ans+=s[i].w;
//		f[u]=v;
//		maxn=max(maxn,s[i].w);
//		cout<<s[i].u<<"--"<<s[i].v<<endl;
//	}
//	cout<<ans<<"\n";
//	for(int i=0;i<k;i++)
//	{
//		int val;
//		cin>>val;
//		
//		int vall=a[0].first+a[1].first;
//		if(vall+val<sum[u][v]) ans-=sum[u][v]-vall-val;
//		else break;
//	}
	
	return 0;
}
