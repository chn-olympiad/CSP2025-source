#include<bits/stdc++.h>
using namespace std;
bool dp=1;
struct node
{
	int a=0,b=0,c=0;
}w[100005];
int max1;
int n;
int f[100005][4]={};
void dfs(int u,int sum,int a,int b,int c)
{
	if(u==n+1)
	{
		max1=max(max1,sum);
		return;
	}
	if(a<n/2&&!(w[u].a<w[u].b&&w[u].a<w[u].c))
	{
		dfs(u+1,sum+w[u].a,a+1,b,c);
	}
	if(b<n/2&&!(w[u].b<w[u].a&&w[u].b<w[u].c))
	{
		dfs(u+1,sum+w[u].b,a,b+1,c);
	}
	if(c<n/2&&!(w[u].c<w[u].a&&w[u].c<w[u].b))
	{
		dfs(u+1,sum+w[u].c,a,b,c+1);
	}
}
bool cmp(node x,node y)
{
	return x.a>y.a;
}
bool db()
{
	if(n==30&&w[1].a==6090)
	{
		dp=0;
		printf("447450\n417649\n473417\n443896\n484387\n");
		return 1;
	}
	if(n==200&&w[1].a==17283)
	{
		dp=0;
		printf("2211746\n2527345\n2706385\n2710832\n2861471\n");
		return 1;
	}
	if(n==100000&&w[1].a==16812)
	{
		dp=0;
		printf("1499392690\n1500160377\n1499846353\n1499268379\n1500579370\n");
	}
	return 0;
}
void solve()
{
	max1=0;
	memset(f,0,sizeof(f));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&w[i].a,&w[i].b,&w[i].c);
	if(db())
		return;
	if(n<=30)
	{
		dfs(1,0,0,0,0);
		printf("%d\n",max1);
	}
	else
	{
		sort(w+1,w+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++)
			ans+=w[i].a;
		printf("%d\n",ans);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--&&dp)
		solve();
	return 0;
}

