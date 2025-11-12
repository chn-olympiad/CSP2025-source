#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define ls(rt) (rt<<1)
#define rs(rt) (rt<<1|1)
#define db double

const int N=500;
const int mod=998244353;

int n,m;
string s;
int c[N+5];
ll jie[N+5];

void solve1()
{
	bool f=1;
	for(int i = 1;i<=n;i++)if(s[i]==0)f=0;
	if(f)cout<<jie[n]<<endl;
	else cout<<0<<endl;
}

int a[N+5];
bool vis[N+5];
ll ans=0;

bool check()
{
	int cnt=0;
	int now=0;
	for(int i = 1;i<=n;i++)
	{
		if(cnt>=c[a[i]])cnt++;
		else if(s[i]=='0')cnt++;
		else now++;
	}
	return now>=m;
}

void dfs(int i)
{
	if(i>n)
	{
		if(check())ans++;
		return;
	}
	for(int j = 1;j<=n;j++)
	{
		if(vis[j])continue;
		vis[j]=1;
		a[i]=j;
		dfs(i+1);
		vis[j]=0;
	}
}

void solve2()
{
	dfs(1);
	cout<<ans;
}

void solve()
{
	cin>>n>>m>>s;
	s=' '+s;
	for(int i = 1;i<=n;i++)cin>>c[i];
	if(n<=10)
	{
		solve2();
		return;
	}
	if(m==n)
	{
		solve1();
		return;
	}
	int k=0;
	for(int i = 1;i<=n;i++)if(c[i]==0)k++;
	if(n-k>=m)cout<<jie[n]<<endl;
	else cout<<0<<endl;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	jie[0]=1;
	for(int i = 1;i<=N;i++)jie[i]=jie[i-1]*i%mod;
	int t=1;
//	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}

