#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000009
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
int n,m,k,check_A=1;
struct Edge 
{
	int u,v,w;
}e[N<<1],ne[N];
int c[20],v[20][10009],ch[20],f[100009];
ll ans=1e18;
bool cmp(const Edge &a,const Edge &b)
{
	return a.w<b.w;
}
int find(int a)
{
	return a==f[a] ?  a : f[a]=find(f[a]);
}
void merge(int a,int b)
{
	f[find(a)]=find(b);
}
void get_ans()
{
	int cnt=m,cntn=n;
	ll nans=0;
	rep(i,1,m,1) e[i]=ne[i];
	rep(i,1,k,1)
	{
		if(ch[i])
		{
			++cntn,nans+=c[i];
			rep(j,1,n,1)
			{
				++cnt;
				e[cnt]=(Edge){cntn,j,v[i][j]};
			}
		}
	} 
	rep(i,1,cntn,1) f[i]=i;
	sort(e+1,e+1+cnt,cmp);
	rep(i,1,cnt,1)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			merge(e[i].u,e[i].v);
			nans+=e[i].w;
		}
	}
	ans=min(ans,nans);
}
void dfs(int f)
{
	if(f==k+1)
	{
		get_ans();
		return;
	}
	ch[f]=1;
	dfs(f+1);
	ch[f]=0;
	dfs(f+1);
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	rep(i,1,m,1)
		cin>>ne[i].u>>ne[i].v>>ne[i].w;
	rep(i,1,k,1)
	{
		cin>>c[i];
		if(c[i]!=0) check_A=0;
		rep(j,1,n,1)
			cin>>v[i][j];
	}
	if(check_A)
	{
		rep(i,1,k,1) ch[i]=1;
		get_ans();
	}
	else
		dfs(1);
	cout<<ans;
	return 0;
}

