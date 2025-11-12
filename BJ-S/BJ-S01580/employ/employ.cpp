#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int a[N],b[N],s[N],vis[N];
int n,m,ans;
void dfs(int l,int nw,int cnt)
{
	if(cnt+n-l+1<m) return;
	if(l==n+1)
	{
		if(cnt>=m) 
		{
			ans++;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		vis[i]=1,b[l]=i;
		int t=nw,nt=cnt+1;
		if(nw>=a[i]||s[l]==0) t++,nt--;
		dfs(l+1,t,nt);
		vis[i]=0;
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		s[i]=c-'0';
		if(s[i]) ct++;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=18)
	{
		dfs(1,0,0);
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
