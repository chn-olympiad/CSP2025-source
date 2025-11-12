#include <bits/stdc++.h>
using namespace std;
int read()
{
	int res = 0,f = 1;
	char ch = getchar();
	while (ch<'0'||ch>'9') f = (ch=='-'?-f:f),ch = getchar();
	while (ch>='0'&&ch<='9') res = (res<<3)+(res<<1)+(ch^48),ch = getchar();
	return res*f;
}
void write(long long x)
{
	if (x<0) putchar('-'),x=-x;
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writech(long long x,char ch){write(x),putchar(ch);}
const int N = 1e4+5,MM = 1e6+5,M = 1e3+5;
int n,m,k;
struct way{int x,y,z;} w[MM];
int c[15][N];
int a[M][M];
bool cmp(way x,way y){return x.z<y.z;}
int f[N],sz[N];
int findroot(int x){return f[x]==x?x:f[x]=findroot(f[x]);}
long long ans;
void add(int x,int y,int z)
{
	int xx = findroot(x),yy = findroot(y);
	if (xx==yy) return ;
	if (sz[xx]<sz[yy]) swap(xx,yy);
	f[yy]=xx;
	sz[xx]+=sz[yy];
	ans+=z;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for (int i = 1; i <= m; i++) w[i].x=read(),w[i].y=read(),w[i].z=read();
	for (int i = 1; i <= n; i++) f[i]=i,sz[i]=1;
	if (k==0)
	{
		sort(w+1,w+m+1,cmp);
		for (int i = 1; i <= m; i++) add(w[i].x,w[i].y,w[i].z);
		write(ans);
		return 0;
	}
	bool flagA=true;
	for (int i = 1; i <= k; i++)
	{
		c[i][0]=read();
		for (int j = 1; j <= n; j++) c[i][j]=read();
		if (c[i][0]!=0) flagA=false;
	}
	if (flagA&&n<=1000)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j]=2e9;
		for (int i = 1; i <= m; i++)
		{
			int x=w[i].x,y=w[i].y,z=w[i].z;
			a[x][y]=min(a[x][y],z);
			a[y][x]=min(a[x][y],z);
		}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= n; k++)
				a[j][k]=min(a[j][k],c[i][j]+c[i][k]);
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j]!=2e9) w[++cnt]={i,j,a[i][j]};
			}
		}
		sort(w+1,w+cnt+1,cmp);
		for (int i = 1; i <= cnt; i++) add(w[i].x,w[i].y,w[i].z);
		write(ans);
	}
	sort(w+1,w+m+1,cmp);
	for (int i = 1; i <= m; i++) add(w[i].x,w[i].y,w[i].z);
	write(ans);
	return 0;
}

