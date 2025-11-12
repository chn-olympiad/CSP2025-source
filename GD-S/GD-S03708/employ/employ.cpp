#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=505,mod=998244353;
int n,m;
string s;
int a[N];
int cnt;
bool vis[N];

bool check(string p)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(cnt>=p[i-1]-'0'||s[i-1]=='0')
			++cnt;
	
	return n-cnt>=m;
}

void dfs(int now,string p)
{
	if(now>n&&check(p)) cnt=(cnt+1)%mod;
	else
		for(int i=1;i<=n;i++)
			if(!vis[i])
			vis[i]=1,
			dfs(now+1,p+char(a[i]+'0')),
			vis[i]=0;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);

	cin>>n>>m>>s;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	dfs(1,"");
	
	cout<<cnt;
	
	return 0;
}
/*
3 2
101
1 1 2
*/
