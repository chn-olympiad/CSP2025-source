#include<bits/stdc++.h>
using namespace std;
int fa[10010];
int u[1000010],v[1000010],w[1000010],a[11][1000010];
int c[12];
int n,m,k,nn;
struct edg{
	int u,v,w;
};
edg e[1000010];
bool cmp(edg e1,edg e2)
{
	return e1.w<e2.w;
}
int find(int x)
{
	if(x==fa[x])
	{
		return x;
	}
	return x=find(fa[x]);
}
bool liantong()
{
	for(int i=1;i<=nn;i++)
	{
		if(find(i)!=find(1))
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	int flag=1;
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		if(c[i]!=0)
		{
			flag=0;
		}
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	if(flag==1)
	{
		nn=n;
		int t=m+1;
		for(;n<nn+k;n++)
		{
			for(int i=1;i<=nn;i++)
			{
				e[t].u=n+1;
				e[t].v=i;
				e[t].w=a[n-nn+1][i];
				t++; 
			}
		}
	} 
	
	sort(e+1,e+1+m+n*k,cmp);
	
	if(liantong())
	{
		cout<<0;
		return 0;
	}
	long long ans=0;
	int q=1;
	while(!liantong())
	{
		
		int fx=find(e[q].u),fy=find(e[q].v);
		if(fx!=fy)
		{
			fa[fx]=fy;
			//cout<<"*"<<fx<<fy<<"*";
			ans+=e[q].w;
			//cout<<e[q].u<<" "<<e[q].v<<" "<<e[q].w<<endl;
			
		}
		q++;
		
	}
	cout<<ans;
	return 0;
}

