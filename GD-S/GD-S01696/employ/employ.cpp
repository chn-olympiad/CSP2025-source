#include<bits/stdc++.h>
using namespace std;
const int N=510,MOD=998244353;
long long n,m,c[N],s[N],ans;
string tmp;
bool vis[N];
void dfs(long long now,long long lq)
{
	if(now>n)
	{
		ans+=(lq>=m);
		ans%=MOD;
		return;
	}
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			dfs(now+1,lq+(s[now]&&(now-1-lq)<c[i]));
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>tmp;
	for(long long i=1;i<=n;i++)
	{
		cin>>c[i];
		s[i]=tmp[i-1]-'0';
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
