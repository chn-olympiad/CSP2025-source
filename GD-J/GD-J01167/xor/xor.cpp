#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int a[N], vis[N], maxnum, ans, n;
bool cmp(int x, int y)
{
	return x>y;
}
void dfs(int num, int maxn, int len, int t)
{
	if(len>2*maxn)
		ans++;
	if(num==maxnum)
		return ;
	for(int i=t+1;i<=n;i++)
	{
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(num+1, max(maxn, a[i]), len+a[i], i);
		vis[i]=0;
	}
}
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k, ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<n/2;
//	for(maxnum=3;maxnum<=n;maxnum++)
//		dfs(0, 0, 0, 0);
//	cout<<ans;
	return 0;
}

