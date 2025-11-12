#include<bits/stdc++.h>
#define int long long
using namespace std;
bool Mst;
const int N=1e4+10,M=1e6+10;
int n,m,k;
int b[M<<1][2],w[M<<1];
int b1[M<<1][2],w1[M<<1],lb1; 
int c[N];
int a[15][N];
int ord[M<<1],val[M<<1];
int shu[M<<1][3];

bool cmp(int x,int y)
{
	return val[x]<val[y];
}

int fa[N];
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

bool flag[N];
bool Med;
signed main()
{
//	cerr<<"Memory:"<<(&Med-&Mst)/1048576.0<<" MiB\n";
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i][0]>>b[i][1]>>w[i];
	}
	for(int i=1;i<=k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			lb1++,b1[lb1][0]=i,b1[lb1][1]=j,w1[lb1]=a[i][j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		ord[i]=i,val[i]=w[i];
	}
	sort(ord+1,ord+1+m,cmp);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	int le=0;
	for(int i=1;i<=m;i++)
	{
		int i1=ord[i];
		int x=b[i1][0],y=b[i1][1];
		if(find(x)==find(y)) continue;
		fa[fa[x]]=y;
		le++,shu[le][0]=x,shu[le][1]=y,shu[le][2]=w[i1];
	}
	for(int i=1;i<=le;i++)
	{
		b[i][0]=shu[i][0],b[i][1]=shu[i][1];
		w[i]=shu[i][2];
	}
	m=le;
	
	for(int i=1;i<=lb1;i++)
	{
		ord[i]=i,val[i]=w1[i];
	}
	sort(ord+1,ord+1+lb1,cmp);
	le=0;
	for(int i=1;i<=lb1;i++)
	{
		int i1=ord[i];
		int x=b1[i1][0],y=b1[i1][1];
		shu[i][0]=x,shu[i][1]=y,shu[i][2]=w1[i1];
	}
	for(int i=1;i<=lb1;i++)
	{
		b1[i][0]=shu[i][0],b1[i][1]=shu[i][1];
		w1[i]=shu[i][2];
	}
	int ans=1e18;
	for(int s=0;s<(1<<k);s++)
	{
		int tmp=0;
		int sum=n;
		for(int j=1;j<=k;j++)
		{
			if(s&(1<<(j-1)))
			{
				tmp=tmp+c[j];
				sum++;
				flag[j]=1;
			}
			else flag[j]=0;
		}
		for(int j=1;j<=n+k;j++)
		{
			fa[j]=j;
		}
		int l=1,l1=1,cnt=0;
		while(cnt<sum-1)
		{
			while(l1<=lb1 && !flag[b1[l1][0]]) l1++;
			if(l>m && l1>lb1) break;
			int typ=-1;
			if(l<=m) typ=0;
			if(l1<=lb1)
			{
				if(typ==-1 || w1[l1]<w[l])
				{
					typ=1;
				}
			}
			int x,y,z;
			if(typ==0)
			{
				x=b[l][0],y=b[l][1],z=w[l];
				l++;
			}
			else
			{
				x=b1[l1][0]+n,y=b1[l1][1],z=w1[l1];
				l1++;
			}
			if(find(x)!=find(y))
			{
				cnt++;
				fa[fa[x]]=fa[y];
				tmp+=z;
			}
		}
//		cerr<<l<<" "<<l1<<" "<<m<<" "<<lb1<<endl;
//		cerr<<s<<" "<<tmp<<endl;
		ans=min(ans,tmp);
	}
	cout<<ans<<endl;
}
/*
road


g++ road.cpp -o road.exe
g++ check.cpp -o check.exe
./road.exe
./check.exe


4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/ 
