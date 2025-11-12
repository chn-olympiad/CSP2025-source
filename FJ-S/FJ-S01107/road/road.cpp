#include<bits/stdc++.h>
using namespace std;
const int maxn=10050,maxm=10000500,maxk=50;
int n,m,k,g[maxk][maxn],t[maxn][maxn],fa[maxn],zl=0,gk[maxk],s[maxk];
struct node{
	int a[5];
}l[maxm];
long long ans=0;
bool cmp(node x,node y)
{
	return x.a[3]<y.a[3];
}
int find(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	if(find(x)!=find(y))
		fa[fa[x]]=fa[y];
	return;	
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l[i].a[1],&l[i].a[2],&l[i].a[3]);
		t[l[i].a[1]][l[i].a[2]]=l[i].a[3];
		t[l[i].a[2]][l[i].a[1]]=l[i].a[3];
	}
	for(int i=1;i<=k;i++)
		for(int j=0;j<=n;j++)
		{
			scanf("%d",&g[i][j]);
			t[n+i][j]=g[i][j]+g[i][0];
		}
	for(int i=1;i<=n+k;i++)
		fa[i]=i;
	m=0;
	for(int i=2;i<=n+k;i++)
		for(int j=1;j<i;j++)
			if(t[i][j]!=0)
			{
				l[++m].a[1]=i;
				l[m].a[2]=j;
				l[m].a[3]=t[i][j];
			}
	sort(l+1,l+m+1,cmp);
	for(int i=1;i<=m;i++)
		if(find(l[i].a[1])!=find(l[i].a[2]))
		{
			if(l[i].a[1]>=n&&!gk[l[i].a[1]-n])
			{
				for(int j=i+1;j<=m;j++)
					if(l[i].a[1]==l[j].a[1])
						l[j].a[3]-=g[l[i].a[1]-n][0];
			}
			else
				zl++;
			gk[l[i].a[1]-n]++;
			s[l[i].a[1]-n]=l[i].a[2];
			merge(l[i].a[1],l[i].a[2]);
			ans+=l[i].a[3];
			if(zl==n-1)
				break;
		}
	for(int i=1;i<=k;i++)
		if(gk[i]==1)
			ans-=(g[i][0]+g[i][s[i]]);
	printf("%lld",ans);
	return 0;
}
