#include <bits/stdc++.h>
using namespace std;
int n,m,k;
int c[200010],rd[200010];
struct node
{
	int x,y,w,f;
	bool operator < (const node&cmp) const
	{
		return w<cmp.w;
	}
};
vector<node> v;
int f[200010];
int find(int x){return x==f[x]?x:f[x]=find(f[x]);}
bool flag[200010];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v.push_back({a,b,c,0});
	}
	for(int i=1;i<=k;i++)
	{
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%d",&x);
			v.push_back({j,i+n,x,0});
		}
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n+k;i++) f[i]=i;
	int t=v.size();
	long long cnt=0;
	for(int i=0;i<t;i++)
	{
		int x=find(v[i].x),y=find(v[i].y),w=v[i].w;
		if(x==y) continue;
		cnt+=w;
		f[x]=y;v[i].f=1;
		rd[x]++;rd[y]++;
	}
	for(int i=n+1;i<=n+k;i++)
	{
		if(rd[i]>=2) cnt+=c[i-n];
		else flag[i-n]=1;
	}
	for(int i=0;i<t;i++)
	{
		if(v[i].f && (flag[v[i].x] || flag[v[i].y])) cnt-=v[i].w;
	}
	cout<<cnt;
	return 0;
}
