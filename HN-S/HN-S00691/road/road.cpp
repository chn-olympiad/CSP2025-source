#include<bits/stdc++.h>
using namespace std;
const int N=1e4+200,M=1e6+200,K=13;
struct node{
	int u,v,w;
}ee[M],e[N],te[N*K];
int c[K],a[K][N];
int n,m,k;
long long ans;
int fa[N];
int find(int x)
{return fa[x]==x?x:fa[x]=find(fa[x]);}
bool cmp(node A,node B)
{return A.w<B.w;}
int chos[K];
void get_ans()
{
	int tot=0;
	for(int i=1;i<n;i++)te[++tot]=e[i];
	long long sum=0;
	int nn=n;
	for(int i=1;i<=k;i++)
		if(chos[i])
		{
			nn++,sum+=c[i];
			for(int j=1;j<=n;j++)
				if(a[i][j]<e[n-1].w)
					te[++tot]={nn,j,a[i][j]};
		}
	if(nn==n)return ;
	for(int i=1;i<=nn;i++)fa[i]=i;
	sort(te+1,te+tot+1,cmp);
	int cnt=0;
	for(int i=1;i<=tot;i++)
	{
		int fu=find(te[i].u),fv=find(te[i].v);
		if(fu==fv)continue;
		fa[fu]=fv,cnt++,sum+=te[i].w;
		if(sum>ans||cnt==nn-1)break;
	}
	ans=min(ans,sum);
	return ;
}
void dfs(int x)
{
	if(x>k)
	{
		get_ans();
		return ;
	}
	chos[x]=1;
	dfs(x+1);
	chos[x]=0;
	dfs(x+1);
	return ;
}
void read(int &x)
{
	char c=getchar();x=0;
	while(c>'9'||c<'0')c=getchar();
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+c-48,c=getchar();
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	read(n),read(m),read(k);
	for(int i=1,u,v,w;i<=m;i++)
		read(u),read(v),read(w),ee[i]={u,v,w};
	for(int i=1;i<=k;i++)
	{
		read(c[i]);
		for(int j=1;j<=n;j++)
			read(a[i][j]);
	}
	sort(ee+1,ee+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i;
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int fu=find(ee[i].u),fv=find(ee[i].v);
		if(fu==fv)continue;
		fa[fu]=fv,e[++cnt]=ee[i],ans+=ee[i].w;
		if(cnt==n-1)break;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
