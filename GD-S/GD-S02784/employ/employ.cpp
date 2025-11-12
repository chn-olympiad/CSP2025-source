#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 2025

using namespace std;

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

void write(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

char s[N];
ll n,m;
bool td[N];
bool flag[N];
bool nflag=1;
ll mod=998244353;
ll ans;
ll nx[N];
ll a[N];
ll cnt,bd;
ll jc[N];
ll tinum;
ll nxbd;

//inline void work1()
//{
//	ans=1;
//	ll cnt=0;
//	for(ll i=1;i<=n;i++)
//	{
//		if(nx[i]!=0)cnt++;
//	}
//	if(cnt<m)
//	{
//		write(0);
//		return;
//	}
//	for(ll i=1;i<=n;i++)
//	{
//		ans*=i;
//		ans%=mod;
//	}
//	write(ans);
//}

inline bool check()
{
	
	ll bd=0,cnt=0;
	for(ll i=1;i<=n;i++)
	{
		if(nx[a[i]]>bd&&td[i])cnt++;
		else bd++;
	}
	if(cnt>=m)return 1;
	else return 0;
}

void dfs(ll st)
{
	if(st>n)
	{
		if(check())
		{
			ans++;
			ans%=mod;
		}
		else return;
	}
	for(ll i=1;i<=n;i++)
	{
		if(flag[i])continue;
		a[st]=i;
		flag[i]=1;
		if(nx[a[i]]>bd&&td[i])cnt++;
		else bd++;
		if(cnt>=m)
		{
			ans+=jc[n-st];
			ans%=mod;
			if(nx[a[i]]>bd&&td[i])cnt--;
			else bd++;
			a[st]=0;
			flag[i]=0;
			continue;
		}
		dfs(st+1);
		if(nx[a[i]]>bd&&td[i])cnt--;
		else bd--;
		a[st]=0;
		flag[i]=0;
	}
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	jc[1]=1;
	jc[0]=1;
	for(ll i=2;i<=501;i++)
	{
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	scanf("%s",s+1);
	for(ll i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			td[i]=1;
			tinum++;
		}
		else nflag=0;
	}
	for(ll i=1;i<=n;i++)
	{
		nx[i]=read();
		if(!nx[i])nxbd++;
	}
	if(tinum<m)
	{
		write(0);
		return 0;
	}
	if(m==n)
	{
		if(nxbd)write(0);
		else write(jc[n]);
		return 0;
	}
	if(m==1)
	{
		if(nxbd<tinum)ans=jc[n];
		else 
		{
			ans=jc[n];
			ll wr=1;
			while(tinum--)
			{
				wr*=nxbd;
				nxbd--;
				wr%=mod;
			}
			wr*=jc[n-tinum];
			wr%=mod;
			ans-=wr;
			ans+=mod;
			ans%=mod;
		}
		write(ans);
		return 0; 
	}
	if(n<=10)
	{
		dfs(1);
		write(ans);
		return 0;
	}
	write(0);
	return 0;
}
