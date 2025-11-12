#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
char *p1,*p2,buf[100000];
#define nc() getchar()
int read()
{
	int x=0;
	char ch=nc();
	for(;ch<48||ch>57;ch=nc());
	for(;ch>47&&ch<58;ch=nc()) x=(x<<3)+(x<<1)+ch-48;
	return x;
}
void write(long long x)
{
	if(x>9) write(x/10);
	putchar(x%10+48);
	return;
}
constexpr int mod=998244353;
long long ans,f[510]={1};
int c[510],n,m;
bool book[510];
string s;
void dfs(int step,int cnt)
{
	if(step==n)
	{
		if(cnt<=n-m)
		{
			++ans;
		}
		return;
	}
	if(cnt>n-m)
	{
		return;
	}
	if(cnt+m<=step)
	{
		ans=(ans+f[n-step])%mod;
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(!book[i])
		{
			book[i]=1;
			if(s[step]=='0'||c[i]<=cnt)
			{
				dfs(step+1,cnt+1);
			}
			else
			{
				dfs(step+1,cnt);
			}
			book[i]=0;
		}
	}
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	cin>>s;
	for(int i=1;i<=n;++i)
	{
		c[i]=read();
		f[i]=(f[i-1]*i)%mod;
	}
	dfs(0,0);
	write(ans);
	return 0;
}//Ren5Jie4Di4Ling5%
/*
3 2
101
1 1 2
*/
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
