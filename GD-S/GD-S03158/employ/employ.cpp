#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=510;
bool b[N],vis[N];
ll c[N],a[N];
string s;
ll n,m,ans;
bool check()
{
	ll num=0;
	for(int i=1;i<=n;i++)
		if(num>=c[a[i]]) num++;
		else if(!b[i]) num++;
	return (n-num>=m);
}
void dfs(ll h)
{
	if(h>n)
	{
		ans+=check();
		return ;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1,a[h]=i;
			dfs(h+1);
			vis[i]=0,a[h]=0;
		}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		b[i]=(s[i-1]=='1');
	dfs(1); 
	cout<<ans;
	return 0;
}
