#include<bits/stdc++.h>
using namespace std;
long long tot,C[20],ans;
int k,len,n,m,nn,cnt[100005],s[100005],mp[20][10005],flag[20];
bool vis[20][100005];
int find_s(int x)
{
	if(s[x]==x)return x;
	else return s[x]=find_s(s[x]);
}
struct edge{
	int u,v,w;
}e[3000005];
void add(int a,int b,int c)
{
	len++;
	e[len].u=a;
	e[len].v=b;
	e[len].w=c;
	return ;
}
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=n;++i)s[i]=i;
	nn=n;
	for(int i=1;i<=k;++i)
	{
		nn++;
		cin>>C[i];
		int w;
		for(int j=1;j<=n;++j)
		{
			cin>>mp[i][j];
		}
	}
	sort(e+1,e+1+len,cmp);
	for(int i=1;i<=len;++i)
	{
		int l=find_s(e[i].u),r=find_s(e[i].v);
		if(l!=r)
		{
			int temp=e[i].w,tt=0;
			for(int j=1;j<=k;++j)
			{
				if(temp>(vis[j][e[i].u]==0)*mp[j][e[i].u]+(vis[j][e[i].v]==0)*mp[j][e[i].v]+C[j]*(flag[j]==0))
				{
					temp=(vis[j][e[i].u]==0)*mp[j][e[i].u]+(vis[j][e[i].v]==0)*mp[j][e[i].v]+C[j]*(flag[j]==0);
					tt=j;
				}
			}
			if(tt!=0)
			{
				vis[tt][e[i].u]=1;
				vis[tt][e[i].v]=1;
				flag[tt]=1;
			}
			s[l]=r;
			ans+=temp;
		}
	}
	cout<<ans;
	return 0;
}
