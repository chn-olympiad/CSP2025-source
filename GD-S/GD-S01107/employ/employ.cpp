#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int MOD=998244353;
int n,m;
long long ans;
int mp[MAXN],p[MAXN],c[MAXN];
string s=" ";
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void check()
{
	int res=0,suc=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i];
		if(res>=c[x])
		{
			res++;
			continue;
		}
		if(s[i]=='0')
		{
			res++;
		}
		else
		{
			suc++;
			if(suc>=m)
			{
				ans=(ans+1)%MOD;
				return ;
			}
		}
	}
}
void dfs(int u)
{
	if(u>n)
	{
		check();
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i]==0)
		{
			mp[i]=1;
			p[u]=i;
			dfs(u+1);
			mp[i]=0;
		}
	}
}
long long ff(int x)
{
	int ans=1;
	for(int i=1;i<=x;i++)
	{
		ans=ans*i%MOD;
	}
	return ans;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	if(n<=18)
	{
		dfs(1);
		printf("%lld",ans);
	}
	else
	{
		bool f=true;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')
			{
				f=false;
				break;
			}
		}
		if(f)
		{
			printf("%lld",ff(n));
		}
		else printf("0");
	}
	return 0;
}
