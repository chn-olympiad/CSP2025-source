#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N_ 505
#define P pair<ll,ll>
#define inf 1000000000000
ll read()
{
	char ch=getchar();ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
ll n,m,cnt[N_],c[N_],p=998244353,a[N_],ans;
bool vis[N_]; 
string s;
bool check()
{
	ll fail=0,tot=0;
	for(int i=1;i<=n;i++)
	{
		if(fail>=c[a[i]]||s[i-1]=='0')
		{
			fail++;
			continue;
		}
		else
		tot++;
	}
	if(tot>=m)return 1;
	return 0;
}
void dfs(ll st)
{
	if(st>n)
	{
		if(check())ans++;
		return ; 
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		a[st]=i;
		vis[i]=1;
		dfs(st+1);
		vis[i]=0;
		a[st]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=0;i<s.size();i++)
	cnt[s[i]-48]++;
	if(cnt[1]<m){
		cout<<0;
		return 0;
	}
	dfs(1); 
	cout<<ans;
	return 0;
}

