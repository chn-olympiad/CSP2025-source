#include<bits/stdc++.h>
using namespace std;
int n,m,k,xx,yy,cnt=1;
long long ans=0;
int f[10015],v[15][10005];
int find(int x)
{
	if (f[x]==x) return x;
	else return f[x]=find(f[x]);
}
struct road{int a,b,c;}r[1100005];
bool cmp(road x,road y){return x.c<y.c;}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++) {scanf("%d %d %d",&r[i].a,&r[i].b,&r[i].c);cnt++;}
	for (int i=1;i<=k;i++)
	{
		f[n+i]=n+i;
		scanf("%d",&v[i][0]);
		for (int j=1;j<=n;j++)
		{
			scanf("%d",&v[i][j]);
			r[cnt].a=n+i,r[cnt].b=j,r[cnt].c=v[i][j],cnt++;
		}
	}
	sort(r+1,r+cnt,cmp);
	for (int i=1;i<cnt;i++)
	{
		xx=find(r[i].a),yy=find(r[i].b);
		if (xx==yy) continue;
		else ans+=r[i].c,f[yy]=xx;
	}
	printf("%lld",ans);
	return 0;
}
