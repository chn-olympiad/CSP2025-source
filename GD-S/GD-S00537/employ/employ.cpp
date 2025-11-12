#include <iostream>
#include <algorithm>

using namespace std;

const int N=505;
const long long MOD=998244353;

int n,m,c[N];
bool s[N];

bool vis[N];
int a[N];

int ans;

void solve()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==0) cnt++;
		else if(cnt>=c[a[i]]) cnt++;
	}
	if(n-cnt>=m) ans++;
}

void dfs(int x)
{
	if(x==n+1)
	{
		solve();
		return;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		
		vis[i]=1,a[x]=i;
		dfs(x+1);
		vis[i]=0,a[x]=0;
	}
}


int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		char x; cin>>x;
		s[i]=x=='1';
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	
	dfs(1);
	
	cout<<ans;
	
	return 0;
}
