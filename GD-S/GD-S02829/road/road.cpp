#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ss
{
	int first,second,third;
	bool operator<(ss y)const
	{
		return first<y.first;
	}
}f[1000010],p[20][110010],a[20][10010],ck[10010];
int n,m,K,g,u,o,c[20],fa[10010],pp[20];
long long po,Min=2e18;
int fi(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=fi(fa[x]);
}
void hs(const int q)
{
	if(q==K+1)
	{
		long long qq=0;
		for(int i=1;i<=n+K;i++)
			fa[i]=i;
		for(int i=1;i<=pp[q];i++)
			if(fi(p[q][i].second)!=fi(p[q][i].third))
			{
				fa[fi(p[q][i].second)]=fi(p[q][i].third);
				qq=qq+p[q][i].first;
			}
		Min=min(Min,qq+po);
		return;
	}
	pp[q+1]=pp[q];
	for(int i=1;i<=pp[q];i++)
		p[q+1][i]=p[q][i];
	p[q+1][pp[q+1]+1]={(int)1e9,0,0};
	hs(q+1);
	int l=1,r=1;
	pp[q+1]=pp[q]+n;
	for(int i=1;i<=pp[q+1];i++)
		p[q+1][i]=(p[q][l].first<=a[q][r].first?p[q][l++]:a[q][r++]);
	p[q+1][pp[q+1]+1]={(int)1e9,0,0};
	po+=c[q];
	hs(q+1);
	po-=c[q];
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>K;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>o>>g;
		f[i]={g,u,o};
	}
	for(int i=1;i<=K;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>u;	
			ck[j]={u,n+i,j};
		}	
		sort(ck+1,ck+n+1);
		for(int j=1;j<=n;j++)
			a[i][j]=ck[j];
		a[i][n+1]={(int)1e9,0,0};
	}
	sort(f+1,f+m+1);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		if(fi(f[i].second)!=fi(f[i].third))
		{
			fa[fi(f[i].second)]=fi(f[i].third);
			p[1][++pp[1]]=f[i];
		}
	p[1][pp[1]+1]={(int)1e9,0,0};
	hs(1);
	cout<<Min;
	return 0;
}

