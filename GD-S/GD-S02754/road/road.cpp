#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
int n,m,k,f[10021],siz[10021],c[12],ans;
struct edge
{
	int u,v,w;
}E[1000011],egs[13][20091],a[12][10091];
void ini()
{
	for(int i=1;i<=n+k;i++) f[i]=i,siz[i]=1;
}
int find(int u)
{
	if(u==f[u]) return u;
	return f[u]=find(f[u]);
}
void merg(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return;
	if(siz[u]<siz[v]) swap(u,v);
	f[v]=u; 
	siz[u]+=siz[v];
}
int cou;
bool cmp(edge a,edge b)
{
	return a.w<b.w;
}
namespace HAP
{
	void work1(edge *E,int m)
	{
		cou=0;
		ini();
		int len=0;
		for(int i=1;i<=m;i++)
		{
			if(find(E[i].u)!=find(E[i].v))
			{
				E[++len]=E[i];
				merg(E[i].u,E[i].v);
				cou+=E[i].w;
			}
		}
	}
}
void dfs(int w,int ccos,int mstcos,int edgnum)
{
	if(w==k+1)
	{
//		cout<<">>"<<ccos+mstcos<<"\n";
		ans=min(ans,ccos+mstcos);
		return;
	}
	for(int i=1;i<=edgnum;i++)
	{
		egs[w+1][i]=egs[w][i];
	}
	dfs(w+1,ccos,mstcos,edgnum);
//	for(int i=1;i<=edgnum;i++)
//	{
//		cout<<egs[w][i].u<<" "<<egs[w][i].v<<" "<<egs[w][i].w<<"\t";
//	}
//	cout<<"\nMERG "<<w<<"\n";
	int l=1,r=1;
	while(l!=edgnum+1||r!=n+1)
	{
		if(l==edgnum+1)
		{
			egs[w+1][l+r-1]=a[w][r];
			r++;
		}
		else if(r==n+1)
		{
			egs[w+1][l+r-1]=egs[w][l];
			l++;
		}
		else if(a[w][r].w<egs[w][l].w)
		{
			egs[w+1][l+r-1]=a[w][r];
			r++;
		}
		else
		{
			egs[w+1][l+r-1]=egs[w][l];
			l++;
		}
	}
//	for(int i=1;i<=edgnum+n;i++)
//	{
//		cout<<egs[w+1][i].u<<" "<<egs[w+1][i].v<<" "<<egs[w+1][i].w<<"\t";
//	}
//	cout<<"\n";
	HAP::work1(egs[w+1],edgnum+n);
//	for(int i=1;i<=edgnum+1;i++)
//	{
//		cout<<egs[w+1][i].u<<" "<<egs[w+1][i].v<<" "<<egs[w+1][i].w<<"\t";
//	}
//	cout<<"\n";
	dfs(w+1,ccos+c[w],cou,edgnum+1);
}
signed main()
{
//	freopen("road4.in","r",stdin);
//	freopen("club5.out","w",stdout);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>E[i].u>>E[i].v>>E[i].w;
	}
	sort(E+1,E+m+1,cmp);
	HAP::work1(E,m);
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j].w;
			a[i][j].u=n+i;
			a[i][j].v=j;
		}
		sort(a[i]+1,a[i]+n+1,cmp);
	}
	for(int i=1;i<n;i++)
	{
		egs[1][i]=E[i];
	}
	ans=cou;
	dfs(1,0,cou,n-1);
	cout<<ans;
}
/*
?诡异
枚举哪些特殊点改造
然后就是模板最小生成树
当然这是违法的
找出原图最小生成树，然后其他边没有用
显然
做到 n2^k log n 
去掉 log 的方法是归并排序 
哦多乘了 k
其实我每次都 check+merg 是对的
写成 dfs 
*/
