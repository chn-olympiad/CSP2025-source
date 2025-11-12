#include<bits/stdc++.h>
using namespace std;
int n,m,k,f[10010],xx,yy,c[20],a[20][10010],b[20];
long long cnt,ans,sum;
struct node{
	int u,v,w;
}r[1000010];
bool cmp(node a,node b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x)	return f[x];
	return f[x]=find(f[x]);
}
void dfs(int len,int num,int pos)
{
	if(len==num+1)
	{
		sum=m;
		ans=0;
		for(int i=1;i<=n;i++)
			f[i]=i;
		for(int i=1;i<=num;i++)
		{
			ans+=c[b[i]];
			for(int j=1;j<=n;j++)
			{
				sum++;
				r[sum].u=b[i]+n;
				r[sum].v=j;
				r[sum].w=a[b[i]][j];
			}
		}
		sort(r+1,r+1+sum,cmp);
		for(int i=1;i<=sum;i++)
		{
			xx=find(r[i].u);
			yy=find(r[i].v);
			if(xx!=yy)
			{
				ans+=r[i].w;
				f[xx]=yy;
			}
		}
		cnt=min(cnt,ans);
		return ;
	}
	for(int i=pos+1;i+num-len<=k;i++)
	{
		b[len]=i;
		dfs(len+1,num,i);
	}
	return ;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>r[i].u>>r[i].v>>r[i].w;
	sort(r+1,r+1+m,cmp);
	for(int i=1;i<=m;i++)
	{
		xx=find(r[i].u);
		yy=find(r[i].v);
		if(xx!=yy)
		{
			cnt+=r[i].w;
			f[xx]=yy;
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,i,0);
	}
	cout<<cnt<<'\n';
	return 0;
}
