#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,f[10050],ans=1e18,c[15][10005];

struct R
{
	int u,v,w;
}z;

bool cmp(R x,R y)
{
	return x.w<y.w;
}

int fnd(int x)
{
	if(f[x]==x)
	  return x;
	return f[x]=fnd(f[x]);
}

R b[1100050],e[1100050];//边

int shu(int numb,int numd)  //numb边的条数 ,numd点的个数 
{
	int sum=0;
	for(int i=1;i<=numd;i++)
	  f[i]=i;
	for(int i=1;i<=numb;i++)
	  e[i]=b[i];
	sort(e+1,e+1+numb,cmp);
	for(int i=1;i<=numb;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(fnd(u)!=fnd(v))
		{
			f[f[u]]=f[f[v]];
			sum+=w;
		}
	}
	return sum;
}

void dfs(int x,int numb,int numd,int sum)  //第x个乡村，num条边 
{
  if(x==k+1)
  {
  	ans=min(ans,shu(numb,numd)+sum);
  	return ; 
  }
  dfs(x+1,numb,numd,sum);
  for(int i=1;i<=n;i++)
  {
  	z.u=i;
  	z.v=n+x;
  	z.w=c[x][i];
  	b[numb+i]=z;
  }
  dfs(x+1,numb+n,numd+1,sum+c[x][0]);
}

bool checkA()
{
	for(int i=1;i<=k;i++)
	{
		if(c[i][0]>0)
		  return 0;
		bool ynn=0;
		for(int j=1;j<=n;j++)
		  if(c[i][j]==0)
		    ynn=1;
		if(!ynn)
		  return 0;
	}
	return 1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		z.u=u,z.v=v,z.w=w;
		b[i]=z;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=0;j<=n;j++)
		  cin>>c[i][j];
	}
	if(checkA())
	{
		int cnt=0;
		for(int j=1;j<=k;j++)
		{
			for(int i=1;i<=n;i++)
		  	{
			  	z.u=i;
			  	z.v=n+j;
			  	z.w=c[j][i];
			  	++cnt;
			  	b[cnt+m]=z;
		  	}
		}
		cout<<shu(m+n*k,n+k)<<"\n";
	}
	else
	{
		dfs(1,m,n,0);
		cout<<ans<<"\n";
	}
	return 0;
}
