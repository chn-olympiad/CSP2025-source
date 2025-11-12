#include<bits/stdc++.h>
#define pii pair<int,int>
#define allof(o) (o).begin(),(o).end()
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int f[205][105][105];
int a[100005][5];
int n,ans;
void dfs(int x,int c1,int c2,int res)
{
	int c3=x-1-c1-c2;
// cerr<<x<<" "<<c1<<" "<<c2<<" "<<c3<<" "<<res<<'\n';
	if(f[x][c1][c2]>=res)return;
	f[x][c1][c2]=res;
	if(x==n+1)
	{
		ans=max(ans,res);
		return;
	}
	c1++;
	if(c1*2<=n)dfs(x+1,c1,c2,res+a[x][1]);
	c1--;
	
	c2++;
	if(c2*2<=n)dfs(x+1,c1,c2,res+a[x][2]);
	c2--;
	
	c3++;
	if(c3*2<=n)dfs(x+1,c1,c2,res+a[x][3]);
	c3--;
}
void solve()
{
	memset(f,-1,sizeof(f));
	ans=0;
	cin>>n;
	int tsxz_A=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][2]||a[i][3])tsxz_A=0;
	}
	if(tsxz_A)
	{
		vector<int> v;
		for(int i=1;i<=n;i++)
			v.push_back(a[i][1]);
		sort(allof(v));
		reverse(allof(v));
		cout<<accumulate(v.begin(),v.begin()+n/2,0)<<'\n';
		return;
	}
	// if(n<=200)
	{
		dfs(1,0,0,0);
		cout<<ans<<'\n';
		return;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int _;
	for(cin>>_;_--;solve());
	return 0;
}