#include<bits/stdc++.h>
using namespace std;
#define int long long
const int Mod=998244353;
const int N=1e3+10;
int in()
{
	int ans=0,ff=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar())
	{
		if(c=='-')
		{
			ff*=-1;
		}
	}
	for(;isdigit(c);c=getchar())
	{
		ans=ans*10+c-'0';
	}
	return ans*ff;
}
void out(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	if(x>=10)
	{
		out(x/10);
	}
	putchar(x%10+'0');
}
int n,m;
string s;
int c[N];
bool fg1;
int ans;
int a[N];
bool st[N];
void dfs(int num)
{
	if(num==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i-1]=='1'&&i-1-cnt<c[a[i]])
			{
				cnt++;
			}
		}
		if(cnt>=m)
		{
			ans++;
			ans%=Mod;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!st[i])
		{
			st[i]=1;
			a[num]=i;
			dfs(num+1);
			st[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=in(),m=in();
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		c[i]=in();
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]!='1')
		{
			fg1=1;
		}
	}
	if(n<=18)
	{
		dfs(1);
		out(ans%Mod);
	}
	else if(!fg1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=Mod;
		}
		out(ans);
	}
	return 0;
}

