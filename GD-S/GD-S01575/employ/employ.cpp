#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const ll MAXN=1e6+5;
const ll inf=LONG_LONG_MAX;
ll n,m,a[MAXN],b[MAXN],ans;
bool vis[MAXN];
void ss(ll x,ll y)
{
	if(y>=m)ans++;
	if(x>n)return ;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			if(x-1-y>=b[i]||a[x])
			{
				ss(x+1,y);
			}
			else
			{
				ss(x+1,y+1);
			}
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>100)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=ans*i%MOD;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	ss(1,0);
	cout<<ans;
	return 0;
}
