#include<cstring>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<iomanip>
#include<bitset>
#include<deque>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
#define ll long long
#define ull unsigned long long

ll read()
{
	ll x=0,f=1;
	char c=getchar();
	while(c>57 or c<48){if(c==45)f=-1;c=getchar();}
	while(c<58 and c>47)x=x*10+c-48,c=getchar();
	return x*f;
}
void output(ll x)
{
	if(x<0)putchar(45),x=-x;
	if(x<10){putchar(x+48);return;}
	output(x/10);
	putchar((x%10)+48);
}
const ll N=100007;
ll n,ans,T;
ll a[N][3],f[N][3];
void dfs(int x,int p1,int p2,int p3,ll s)
{
	if(p1>n/2 or p2>n/2 or p3>n/2)return;
	if(x==n+1)
	{
		ans=max(ans,s);
		return;
	}
	dfs(x+1,p1+1,p2,p3,s+a[x][0]);
	dfs(x+1,p1,p2+1,p3,s+a[x][1]);
	dfs(x+1,p1,p2,p3+1,s+a[x][2]);
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		ans=0;
		for(ll i=1;i<=n;i++)
			for(ll j=0;j<3;j++)
				a[i][j]=read();
		if(n<=20)
		{
			dfs(1,0,0,0,0);
			output(ans),putchar(10);
		}
		else
		{
			memset(f,0,sizeof f);
			work(1,0,0,0,0,0);
		}
	}
	return 0;
}

