#include<bits/stdc++.h>
using namespace std;
const int M=1000010;
bool vis[100010];
int n,m,k,fa[M],c[20][10010],a[10010];
long long ans;
struct node{
	int a,b,c;
}e[M];
node e2[M];
bool cmp(node a,node b)
{
	return a.c<b.c;
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
long long work(int mm,int nn)
{
	//for(int i=1;i<=m;i++) e2[i]=e[i];
	sort(e2+1,e2+1+mm,cmp);
	long long ret=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int dep=0;
	/*for(int i=1;i<=mm;i++)
	{
		cout<<e2[i].c<<" ";
	}
	cout<<"\n";*/
	for(int i=1;i<=mm;i++)
	{
		//cout<<e2[i].c<<"\n";
		int a=e2[i].a,b=e2[i].b;
		int fx=find(a),fy=find(b);
		if(fx==fy) continue;
		fa[fx]=fy;
		ret+=e2[i].c;
		dep++;
		if(dep==nn-1) break;
	}
	return ret;
}
void dfs(long long sum,int now)
{
	if(now>k)
	{
		int nn=n,mm=m,z=0;
		for(int i=1;i<=m;i++)
		{
			e2[++z]=e[i];
		}
		for(int i=1;i<=k;i++)
		{
			if(a[i]==0) continue;
			for(int j=1;j<=n;j++)
			{
				e2[++z]={a[i]+n,j,c[a[i]][j]};
			}
			mm+=n,nn+=1;
		}
		/*for(int i=1;i<=k;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<"\n";*/
		ans=min(ans,sum+work(z,nn));
		//cout<<sum<<" "<<ans<<"\n";
		return;
	}
	for(int i=0;i<=k;i++)
	{
		if(vis[i]) continue;
		if(i!=0) vis[i]=true;
		a[now]=i;
		dfs(sum+(i==0?0:c[i][0]),now+1);
		vis[i]=false;
		//for(int j=cnt+1;j<=cnt+n;j++) e[j]={0,0,0};
	}
}


int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].c;
		e2[i]=e[i];
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++) cin>>c[i][j];
	}
	ans=work(m,n);
	if(k==0)
	{
		cout<<ans;
		return 0;
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
