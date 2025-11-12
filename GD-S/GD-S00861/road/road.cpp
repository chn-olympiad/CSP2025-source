#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e18;
struct e{int u,v,w;}b[1000006];
struct g{int c;e a[10004];}x[15],xc[15];
e s[10004];
int f[10014];
bool cmp(e x,e y){return x.w<y.w;}
int n,m,k;
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
int ans;
int j1[15];
void getans(int cnt)
{
//	cout<<cnt<<'\n';
	int c=0;
	int sum=0;
	for(int j=1;j<=cnt;j++) j1[j]=1,sum+=xc[j].c;
	for(int i=1;i<=n+cnt;i++) f[i]=i;
	for(int i=1;c<n+cnt-1;)
	{
		int U=0,V=0,W=inf,f1=-1;
		while(i<n&&find(s[i].u)==find(s[i].v)) i++;
		if(i<n) U=s[i].u,V=s[i].v,W=s[i].w,f1=0;
		for(int j=1;j<=cnt;j++)
		{
			while(j1[j]<n&&find(xc[j].a[j1[j]].u)==find(xc[j].a[j1[j]].v)) j1[j]++;
			if(j1[j]>n) continue;
			if(xc[j].a[j1[j]].w<W)
			{
				U=xc[j].a[j1[j]].u;
				V=xc[j].a[j1[j]].v;
				W=xc[j].a[j1[j]].w;
				f1=j;
			}
		}
		if(f1==0) i++;
		else j1[f1]++;
		f[find(U)]=find(V);
		c++;
		sum+=W;
//		if(sum>ans) return;
	}
	ans=min(ans,sum);
}
void dfs(int s,int cnt)
{
	if(s==k)
	{
		if(cnt==0) return;
//		cout<<cnt<<'\n';
		getans(cnt);
		return;
	}
	dfs(s+1,cnt);
	xc[cnt+1]=x[s+1];
	dfs(s+1,cnt+1);
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i; 
	for(int i=1;i<=m;i++)
	{
		cin>>b[i].u>>b[i].v>>b[i].w;
	}
	for(int i=1;i<=k;i++)
	{
		cin>>x[i].c;
		for(int j=1;j<=n;j++)
		{
			x[i].a[j].u=i+n;
			x[i].a[j].v=j;
			cin>>x[i].a[j].w;
		}
		sort(x[i].a+1,x[i].a+n+1,cmp);
	}
	sort(b+1,b+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m&&cnt<n-1;i++)
	{
		int fu=find(b[i].u);
		int fv=find(b[i].v);
		if(fu!=fv)
		{
			f[fu]=fv;
			cnt++;
			ans+=b[i].w;
			s[cnt]=b[i];
		}
	}
	dfs(0,0);
	cout<<ans; 
}
