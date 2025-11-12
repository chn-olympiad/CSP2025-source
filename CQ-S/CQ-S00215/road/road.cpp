#include<bits/stdc++.h>
#define N 10005
#define inf 0x7fffffff
#define int long long
using namespace std;
int n,m,k,ans,s,vis[N],r[20][N],f[25000];
vector<int>b[N];
struct node{
	int from,to,val;
}e[1300000];
int find(int x)
{
	if(f[x]==x)return x;
	return f[x]=find(f[x]);
}
int cmp(node x,node y){
	return x.val<y.val;
}
void calc()
{
	int cnt=0;
	for(int i=1;i<=24000;i++)
	f[i]=i;
	for(int i=1;i<=s;i++)
	{
		int u=e[i].from,v=e[i].to,w=e[i].val;
		int x=find(u),y=find(v);
		if(x==y)continue;
		f[x]=y;ans+=w;
		cnt++;
		if(cnt==n+1)break;
	}
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		e[++s]={x,y,z};
	}
	sort(e+1,e+s+1,cmp);
	calc();
	for(int i=1;i<=k;i++)
	{
		int V;scanf("%lld",&V);
		for(int j=1;j<=n;j++)
		e[++s]={n+i,j,0};
		e[++s]={n+i,20000+i,V};
		for(int j=1;j<=n;j++)
		{
			int x;
			scanf("%lld",&x);
			e[++s]={20000+i,j,x};
		}
		ans=min(ans,V);
	}
	cout<<ans;
//	for(int i=1;i<=s;i++)
//	cout<<e[i].from<<" "<<e[i].to<<' '<<e[i].val<<endl;
	return 0;
}
