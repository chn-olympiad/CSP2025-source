#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxm=2e2+10,maxn=3e5+10;
struct node
{
	int cost1,cost2,cost3;
}a[maxm];
struct _node
{
	int val,id,op;
}b[maxn];
bool cmp(_node a,_node b)
{
	return a.val>b.val;
}
int n,ans;
int dp[maxm][maxm/2][maxm/2];
bool vis[maxn];
int cnt[10];
void solve1()
{

	for(int i=1;i<=n;i++)
	{
		cin>>a[i].cost1>>a[i].cost2>>a[i].cost3;
	}
	ans=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j1=0;j1<=n/2&&j1<=i;j1++)
		{
			for(int j2=(i-j1)/2;j2<=n/2&&j1+j2<=i;j2++)
			{
				int j3=(i-j1-j2);
				if(j3>n/2)continue;
				if(j1!=0)dp[i][j1][j2]=max(dp[i-1][j1-1][j2]+a[i].cost1,dp[i][j1][j2]);
				if(j2!=0)dp[i][j1][j2]=max(dp[i-1][j1][j2-1]+a[i].cost2,dp[i][j1][j2]);
				if(j3!=0)dp[i][j1][j2]=max(dp[i-1][j1][j2]+a[i].cost3,dp[i][j1][j2]);
				if(i==n)ans=max(ans,dp[i][j1][j2]);
			}			
		}  
	}
	cout<<ans<<"\n";
	return;	
}
void solve2()
{
	int tot=0;
	bool f=1;
	tot=0;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		int x,y,z;
		cin>>x>>y>>z;
		b[++tot].val=x,b[tot].id=i,b[tot].op=1;
		b[++tot].val=y,b[tot].id=i,b[tot].op=2;
		b[++tot].val=z,b[tot].id=i,b[tot].op=3;
		if(z!=0)f=0;
	}
	if(f)
	{
			
	}
	sort(b+1,b+1+tot,cmp);
	cnt[1]=0,cnt[2]=0,cnt[3]=0;
	ans=0;
	for(int i=1;i<=tot;i++)
	{
		int val=b[i].val,id=b[i].id,op=b[i].op;
		if(vis[id]==1)continue;
		if(cnt[op]+1>n/2)continue;
		ans+=val;
		cnt[op]++;
		vis[id]=1;
	}
	cout<<ans<<"\n";
	return;	
}
void solve()
{
	cin>>n;
	if(n<=200)solve1();
	else solve2();
	return;
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
/*
3 
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0


*/
