#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e3+10, mod=998244353;
int n, a[N], tmp[N], ans;
bool b[N];

int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) putchar('-'), x-=x;
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
void dfs(int k, int x)
{
	if(k>n) return;
	for(int i=x+1; i<=n; i++)
	{
		if(!b[i])
		{
			tmp[k]=a[i];
			int s=0, mx=0;
			for(int i=1; i<=k; i++) mx=max(mx, tmp[i]),s=s+tmp[i];
			if(s>mx*2) ans++; 
			b[i]=1;
			dfs(k+1, i);
			b[i]=0;
		}
	}
} 
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	n=read();
	for(int i=1; i<=n; i++)
	a[i]=read();
	dfs(1, 0);
	write(ans%mod);
	return 0;	
}

