#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,mod=998244353;
ll n,i,ans,a[N],flag=1,f[N];
string s;
map<string,int> mp;
inline void dfs(ll k,ll tot,ll mx,ll num)
{
	if(tot>2*mx&&num>=3)
	 if(!mp[s]) mp[s]=1,ans++;
	if(k>n) return;//cout<<ans<<"\n";
	s.replace(k,1,"1");
	dfs(k+1,tot+a[k],max(mx,a[k]),num+1);
	s.replace(k,1,"0");
	dfs(k+1,tot,mx,num);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	for(i=0;i<=n;i++) s+='0';
	if(n==3) 
	{
		if(a[1]+a[2]+a[3]>2*max( a[1], max(a[2],a[3]) ) ) cout<<1;
		else cout<<0;
		return 0;
	}
	if(flag)
	{
		cout<<n*(n-1)*(n-2)/6%mod;
		return 0;
	}
	dfs(0,0,0,0);
	cout<<ans/2%mod;
	return 0;
	return 0; 
 }
//5
//1 2 3 4 5
//5
//2 2 3 8 10
//20
//75 28 15 26 12 8 90 42 90 43 14 26 84 83 14 35 98 38 37 1
