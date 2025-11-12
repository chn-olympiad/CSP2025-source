#include<bits/stdc++.h> 
using namespace std;
int n,m,k,m1,cou;
long long s;
long long a[10005][10005];
int c[15],a1[15][10005];
int fa[10005];
int find(int u)
{
	return fa[u]==u?u:fa[u]=find(fa[u]);
}
void eat(int u,int v)
{
	fa[v]=fa[u];
}
struct A{
	int u,v;
	long long w;
}aa[50000005];
bool cmp(A x,A y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		cin>>a[u][v];
		a[v][u]=a[u][v];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a1[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int l=1;l<=k;l++)
			{
				long long f=a1[l][i]+c[l]+a1[l][j];
				a[i][j]=min(a[i][j],f);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cou++;
			aa[cou].u=i;
			aa[cou].v=j;
			aa[cou].w=a[i][j];
		}
	}
	sort(aa+1,aa+cou+1,cmp);
	cou=0;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	while(m1<n-1)
	{
		cou++; 
		if(find(aa[cou].u)!=find(aa[cou].v))
		{
			eat(aa[cou].u,aa[cou].v);
			s+=aa[cou].w;
			m1++;
		}
	}
	cout<<s;
}
