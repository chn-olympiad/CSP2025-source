#include<bits/stdc++.h>
using namespace std;
const int MAXM=1200005;
const int MAXN=20005;
struct s
{
	int u;
	int v;
	int w;
} b[MAXM];
int n,m,k,c,a[MAXN],cnt,aa,f[MAXN];
long long ans;
bool cmp(struct s q,struct s h){return q.w<h.w;}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int uu,vv,ww;
		cin>>uu>>vv>>ww;
		b[i].u=uu;
		b[i].v=vv;
		b[i].w=ww;
	}
	cnt=m;
	for(int i=1;i<=k;i++)
	{
		cin>>c;
		int QAQ;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			if(a[j]==0) QAQ=j;
		}
		for(int j=1;j<=n;j++)
		{
			cnt++;
			b[cnt].u=QAQ;
			b[cnt].v=j;
			b[cnt].w=a[j];
		}
	}
	sort(b+1,b+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		int uu=b[i].u,vv=b[i].v,ww=b[i].w;
		int fu=find(uu),fv=find(vv);
		if(fu!=fv)
		{
			f[fu]=fv;
			ans+=ww;
		}
	}
	cout<<ans;
	return 0;
}
