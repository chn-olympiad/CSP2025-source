#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=998244353;
const int N=505;
int n,m,ans;
int c[N],tp[N];
string s;
int a[N];
int st[N];
bool vis[N];
void dfs(int x)
{
	if(x==n+1)
	{
		int lev=0,sum=0;
		for(int i=1;i<=n;i++)
			if(lev<c[st[i]]&&a[i]==1)
				sum++;
			else lev++;
		if(sum>=m)ans++;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			st[x]=i;
			vis[i]=1;
			dfs(i+1);
			vis[i]=0;
			st[x]=0;
		}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		a[i]=(s[i-1]-'0');
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
