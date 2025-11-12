#include<bits/stdc++.h>
using namespace std;
int x,y,w,z;
int len,n,m,k,ans,minn;
bool v[1000501];
int last[1000021];
struct jj{
	int x,y,w,nex;
}a[2000501];
void add(int x,int y,int w)
{
	len++;
	a[len]={x,y,w,last[y]};
	last[y]=len;
}
void dfs(int xx,int yy)
{
	if (xx==0)
	 return;
	else if (xx==yy) 
	{
		minn=min(minn,ans);
		return;
	}
	for (int i=last[x];;i=a[i].nex)
	{
		v[a[i].y]=1;
		ans+=a[i].w;
		if (a[i].x==0)
		 dfs(a[i].x,y);
	}
	return;
}
int main()
{
	/*freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);*/
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++)
	{
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	/*for (int i=1;i<=k;i++)
	{
		int z;
		cin>>z;
		for (int j=1;j<=n;j++)
		{
			int w;
			cin>>w;
			w+=z;
			add(n+i,j,w);
			add(j,n+i,w);
		}
	}*/
	cin>>x>>y;
	dfs(x,y);
	cout<<minn<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 2

1 1 8 2 4
100 1 3 2 4*/
