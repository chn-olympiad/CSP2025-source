#include<algorithm>
#include<iostream>
#include<cstdio>
#define ll long long
#define Hoshino 520520520520ll
#define MOD 998244353ll
inline void write(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x>9)write(x/10);
	putchar(x%10^48);
}
inline ll read()
{
	ll x=0;bool c=0;char a=getchar();
	for(;a<'0'||a>'9';a=getchar())c|=a==45;
	for(;a>='0'&&a<='9';a=getchar())x=(x<<3)+(x<<1)+(a^48);
	return c?-x:x;
}
#define R read()
using namespace std;

ll n,m,ans=0,T=0;
ll c[502];
bool kind=true,vis[502];
string s;

inline void dfs(ll x,ll cnt)
{
	if(n-cnt<m)return;
	if(x>=n)
	{
		ans=((ans+1)>=MOD?0:(ans+1));
		return;
	}
	if(++T>10000000){write(ans);exit(0);}
	for(ll i=1;i<=n;++i)if(!vis[i])
	{
		vis[i]=1;
		dfs(x+1,cnt+(cnt>=c[i]?1:(s[x]=='1'?0:1)));
		vis[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=R,m=R;
	cin>>s;
	for(ll i=1;i<=n;++i)c[i]=R;
	sort(c+1,c+1+n);
//	for(ll i=0;i<s.length();++i)if(s[i]!='1'){kind=false;break;}
//	if(kind)
//	{
//		
//		ans=1;
//		for(ll i=1;i<=n;++i)ans=ans*i%MOD;
//		write(ans);
//		return 0;
//	}
	dfs(0,0);
	write(ans);
	return 0;
}
