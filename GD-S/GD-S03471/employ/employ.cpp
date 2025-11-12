//Author: mairuisheng
//#pragma GCC optimize(3)
#include<iostream>
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char s;
	s=getchar();
	while(s<48||s>57)
	{
		if(s=='-')f=-f;
		s=getchar();
	}
	while(s>47&&s<58)
	{
		x=(x<<3)+(x<<1)+s-48;
		s=getchar();
	}
	return x*f;
}
constexpr int N=501,MOD=998244353;
int n,m;
int tot;
int a[N],c[N];
bool vis[N];
string s;
void Check()
{
	int i,no=0,sum=0;
	for(i=1;i<=n;++i)
	{
		if(s[i]==48||no>=c[a[i]])++no;
		else ++sum;
	}
	if(sum>=m)
	{
		++tot;
		if(tot==MOD)tot=0;
	}
}
void dfs(int x)
{
	if(x==n)
	{
		Check();
		return;
	}
	int i;
	for(i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			vis[i]=true;
			a[x+1]=i;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
void Work1()
{
	dfs(0);
	printf("%lld",tot);
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	int i,ans=1,o=0;
	cin>>s;
	s=' '+s;
	for(i=1;i<=n;++i)
	{
		c[i]=read();
		if(c[i]==0)++o;
	}
	if(n<=10)
	{
		Work1();
		return 0;
	}
	else
	{
		if(n-o<m)
		{
			puts("0");
			return 0;
		}
		for(i=2;i<=n;++i)ans=ans*i%MOD;
	}
	printf("%lld",ans);
	return 0;
}
