# include <cstdio>
# include <random>
# include <algorithm>
# define int long long
using namespace std;
int n,m,k,s[2000007][3],c[72],b[17][50007][2],fa[50007],bz1[2000007],cnt,sum=1e18+7,t[72],t1,h[72];
std::mt19937 rnd(0);
int min(int x,int y){return x<y?x:y;}
void qsort(int x,int y)
{
	int i=x,j=y,mid=s[rnd()%(y-x+1)+x][2];
	while(i<=j)
	{
		while(s[i][2]<mid) i++;
		while(s[j][2]>mid) j--;
		if(i<=j)
		{
			swap(s[i],s[j]);
			i++,j--;
		}
	}
	if(i<y) qsort(i,y);
	if(x<j) qsort(x,j);
}
void qsort1(int z,int x,int y)
{
	int i=x,j=y,mid=b[z][rnd()%(y-x+1)+x][0];
	while(i<=j)
	{
		while(b[z][i][0]<mid) i++;
		while(b[z][j][0]>mid) j--;
		if(i<=j)
		{
			swap(b[z][i],b[z][j]);
			i++,j--;
		}
	}
	if(i<y) qsort1(z,i,y);
	if(x<j) qsort1(z,x,j);
}
int getfa(int x)
{
	if(fa[x]==x) return x;
	else return fa[x]=getfa(fa[x]);
}
void dg(int x,int ans)
{
	if(x>k)
	{
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=k;i++) h[i]=1;
		int zq=0;
		for(int i=1;i<=cnt;i++)
		{
			for(int j=1;j<=t1;j++)
			{
				while(h[t[j]]<=n&&b[t[j]][h[t[j]]][0]<=s[i][2])
				{
					int x=t[j]+n,y=b[t[j]][h[t[j]]][1],z=b[t[j]][h[t[j]]][0];
					int x1=getfa(x),x2=getfa(y);
					if(x1!=x2)
					{
						zq+=z;
						fa[x1]=x2;
					}
					h[t[j]]++;
				}
			}
			int x=s[i][0],y=s[i][1],z=s[i][2];
			int x1=getfa(x),x2=getfa(y);
			if(x1!=x2)
			{
				zq+=z;
				fa[x1]=x2;
			}
		}
		sum=min(sum,ans+zq);
		return;
	}
	dg(x+1,ans);
	t[++t1]=x;
	dg(x+1,ans+c[x]);
	t1--;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&s[i][0],&s[i][1],&s[i][2]);
	for(int i=1;i<=k;i++)
	{
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&b[i][j][0]);
			b[i][j][1]=j;
		}
	}
	qsort(1,m);
	for(int i=1;i<=k;i++) qsort1(i,1,n);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x=s[i][0],y=s[i][1];
		int x1=getfa(x),x2=getfa(y);
		if(x1!=x2)
		{
			bz1[i]=1;
			fa[x1]=x2;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(bz1[i]==0) continue;
		cnt++;
		s[cnt][0]=s[i][0],s[cnt][1]=s[i][1],s[cnt][2]=s[i][2];
	}
	m=cnt;
	dg(1,0);
	printf("%lld",sum);
	return 0;
}
