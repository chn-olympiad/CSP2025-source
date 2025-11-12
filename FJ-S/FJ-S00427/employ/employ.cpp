# include <bits/stdc++.h>
# define ll long long
using namespace std;
const ll N =505,Mod=998244353;
ll n,c[N],m,ans=0;string s;
bool tis[N];
void dfs(ll sum,ll x)
{
	if(n-sum>=m && x>n){ans=(ans+1)%Mod;return;}
	if(x>n)return;
	for(int i=1;i<=n;i++)
	if(!tis[i])
	{
		tis[i]=1;
		dfs(sum+(s[x-1]=='0' || sum>=c[i]),x+1);
		tis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s[s.size()]=1;
	int Cnt=0;
	for(int i=0;s[i];i++)Cnt+=(s[i]=='0');
	if(Cnt+m>n){cout<<0;return 0;}
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(0,1);
	cout<<ans;
	return 0;
}