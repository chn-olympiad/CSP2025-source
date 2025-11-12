#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int M=5000004,Z=26,N=300000,Q=300000;
int e[M][Z],m,p[N][2],f[20][M],a[M],d[M],head[M],nxt[M],tot,to[M],ll[M],c,rr[M],pos[2][M],bit[M],ans[Q];
char s[M],t[2][M];
vector<int>vi1[M],vi2[M],vi3[M];
void add(int u,int v)
{
	nxt[tot]=head[u];
	to[tot]=v;
	head[u]=tot++;
}
void dfs(int u)
{
	int i;
	ll[u]=++c;
	for (i=head[u];i>-1;i=nxt[i]) dfs(to[i]);
	rr[u]=c;
}
void modify(int p,int x)
{
	int i;
	for (i=p;i<=m;i+=i&-i) bit[i]+=x;
}
int ask(int p)
{
	int x,i;
	x=0;
	for (i=p;i;i-=i&-i) x+=bit[i];
	return x;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q,i,j,k,x,l,o,b,u,y,z,siz;
	scanf("%d%d",&n,&q);
	for (i=0;i<2;i++) for (j=0;j<Z;j++) e[i][j]=i;
	m=2;
	for (i=1;i<=n;i++) for (j=0;j<2;j++)
	{
		scanf("%s",s);
		k=strlen(s);
		x=j;
		for (l=0;l<k;l++)
		{
			if (e[x][s[l]-'a']<2)
			{
				for (o=0;o<Z;o++) e[m][o]=j;
				e[x][s[l]-'a']=m++;
			}
			x=e[x][s[l]-'a'];
		}
		p[i][j]=x;
	}
	for (i=0;i<2;i++) f[0][i]=i;
	b=0;
	for (i=0;i<2;i++) for (j=0;j<Z;j++) if (e[i][j]>1)
	{
		a[b++]=e[i][j];
		f[0][e[i][j]]=i;
		d[e[i][j]]=1;
	}
	for (i=0;i<b;i++)
	{
		u=a[i];
		for (j=0;j<Z;j++) if (e[u][j]<2) e[u][j]=e[f[0][u]][j];
		else
		{
			a[b++]=e[u][j];
			f[0][e[u][j]]=e[f[0][u]][j];
			d[e[u][j]]=d[u]+1;
		}
	}
	for (i=0;i<m;i++) head[i]=-1;
	for (i=2;i<m;i++) add(f[0][i],i);
	for (i=0;i<2;i++) dfs(i);
	for (i=1;i<20;i++) for (j=0;j<m;j++) f[i][j]=f[i-1][f[i-1][j]];
	for (i=1;i<=q;i++)
	{
		for (j=0;j<2;j++)
		{
			scanf("%s",t[j]);
			k=strlen(t[j]);
			x=j;
			for (l=0;l<k;l++)
			{
				x=e[x][t[j][l]-'a'];
				pos[j][l]=x;
			}
		}
		if (strlen(t[0])!=k) continue;
		for (j=0;t[0][j]==t[1][j];j++);
		x=j;
		for (j=k-1;t[0][j]==t[1][j];j--);
		for (;j<k;j++)
		{
			y=pos[0][j];
			z=pos[1][j];
			vi1[ll[y]].push_back(i);
			vi2[ll[y]].push_back(ll[z]);
			for (l=19;l>=0;l--) if (d[f[l][y]]>=j-x+1) y=f[l][y];
			if (d[y]>=j-x+1) y=f[0][y];
			vi1[ll[y]].push_back(-i);
			vi2[ll[y]].push_back(ll[z]);
		}
	}
	for (i=1;i<=n;i++)
	{
		vi3[ll[p[i][0]]].push_back(i);
		vi3[rr[p[i][0]]+1].push_back(-i);
	}
	for (i=1;i<=m;i++)
	{
		siz=vi3[i].size();
		for (j=0;j<siz;j++)
		{
			x=vi3[i][j];
			if (x<0)
			{
				modify(ll[p[-x][1]],-1);
				modify(rr[p[-x][1]]+1,1);
			}
			else
			{
				modify(ll[p[x][1]],1);
				modify(rr[p[x][1]]+1,-1);
			}
		}
		siz=vi1[i].size();
		for (j=0;j<siz;j++)
		{
			x=vi1[i][j];
			y=vi2[i][j];
			if (x<0) ans[-x]-=ask(y);
			else ans[x]+=ask(y);
		}
	}
	for (i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
/*
3 1
a b
aa ab
aa ba
aaa aba
*/
