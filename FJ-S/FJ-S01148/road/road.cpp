#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
struct S
{
	int x,y,w;
	bool operator <(S t)
	{
		return w<t.w;
	}
}e[1000500],c[11][10500],tmp[10500],mk[11][10500];
int tot=0;
int fa[10500];
int find_fa(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find_fa(fa[x]);
}
long long nowans=0;
int n,m,k;
long long ans=inf;
int f[11];
void dfs(int x,int ccnt,long long pref)
{
//	cout << x << "        " << nowans << "         " << ccnt << endl;
	if(x>k)
	{
		ans=min(ans,nowans);
		return;
	}
	for(int i=1;i<n+ccnt;i++) mk[x][i]=tmp[i];
	dfs(x+1,ccnt,pref);
	nowans=pref+f[x];
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int cnt=n+ccnt+1;
	tot=0;
	for(int i=1,j=1;i<n+ccnt,j<=n;)
	{
//		cout << i << ' ' << j << ' ' << nowans << endl;
		S us;
		if(i>=n+ccnt) us=c[x][j],j++;
		else if(j>n) us=mk[x][i],i++;
		else if(c[x][j]<mk[x][i]) us=c[x][j],j++;
		else us=mk[x][i],i++;
		int s=us.x,t=us.y;
		int ss=find_fa(s),tt=find_fa(t);
		if(ss!=tt)
		{
			fa[ss]=tt;
			cnt--;
			tmp[++tot]=us;
			nowans+=us.w;
			if(cnt==1) break;
		}
	}
	dfs(x+1,ccnt+1,pref+f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
	sort(e+1,e+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=n;
	for(int i=1;i<=m;i++)
	{
		int x=e[i].x,y=e[i].y;
		int xx=find_fa(x),yy=find_fa(y);
		if(xx!=yy)
		{
			fa[xx]=yy;
			cnt--;
			tmp[++tot]=e[i];
			nowans+=e[i].w;
			if(cnt==1) break;
		}
	}
//	for(int i=1;i<n;i++) cout << tmp[i].x << ' ' << tmp[i].y << ' ' << tmp[i].w << endl;
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&f[i]);
		for(int j=1;j<=n;j++)
		{
			int w;
			scanf("%d",&w);
			c[i][j]={i+n,j,w};
		}
		sort(c[i]+1,c[i]+1+n);
	}
	dfs(1,0,0);
	printf("%lld\n",ans);
	return 0; 
}
