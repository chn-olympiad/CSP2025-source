#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
const int N=5e5+10;
int n, k, sum[N], a[N];
int ans;
//int q[N], h, t;

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
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	n=read(),k=read();
	for(int i=1; i<=n; i++)
	{
		a[i]=read();
		sum[i]=sum[i-1]^a[i];
	}
	for(int p=1; p<=n; p++)
	{
		int res=0, t=p;
		for(int i=p; i<=n; i++)
		{
			if((sum[i]^sum[t-1])==k) res++,t=i+1;
		}
		ans=max(ans, res);
	}
	write(ans);
	return 0;
}
