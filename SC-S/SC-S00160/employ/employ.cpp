#include<bits/stdc++.h>

#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N = 510,Mod = 998244353;
int n,m;
int a[N],c[N],fac[N];
int A[N],vis[N];
int ans,tmp;
void DFS(int step)
{
	if(step-1-tmp >= m) 
	{
		ans += fac[n-step+1];ans %= Mod;
		return ;
	}
	if(step == n + 1) return ;
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i] = 1;
			A[step] = i;
			if(!a[step] || c[i] <= tmp)
				tmp++;
			DFS(step + 1);
			vis[i] = 0;
			A[step] = 0;
			if(!a[step] || c[i] <= tmp)
				tmp--;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vis[0] = 1;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		a[i] = ch - '0';
		vis[0] &= a[i];
	}
	for(int i=1;i<=n;i++) cin>>c[i],vis[0] &= c[i];
	fac[0] = 1;
	for(int i=1;i<=n;i++) fac[i] = fac[i-1] * i % Mod;
	if(m == n)
	{
		if(vis[0]) cout<<fac[n];
		else cout<<0;
		return 0;
	}
	DFS(1);
	cout<<ans;
	return 0;
}