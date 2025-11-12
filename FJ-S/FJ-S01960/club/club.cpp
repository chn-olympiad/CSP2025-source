#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		{
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=(x<<1)+(x<<3)+(int(ch)^48);
		ch=getchar();
	}
	return x*f;
}

inline void write(LL x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(char(x%10+48));
}

inline void print(LL x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	write(x);
	puts("");
}

const int N=1e5+10;

int n;

struct Node{
	int v1,v2,v3;
	bool operator<(const Node &A){
		if(v1==A.v1)
		{
			if(v2==A.v2)
			{
				return v3>A.v3;
			}
			return v2>A.v2;
		}
		return v1>A.v1;
	}
}a[N];

bool vis[N];

void solve()
{
	n=read();
	bool flag1=1;
	bool flag2=1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;++i)
	{
		a[i].v1=read();
		a[i].v2=read();
		a[i].v3=read();
		if(a[i].v2 || a[i].v3)
		{
			flag1=0;
		}
		if(a[i].v3)
		{
			flag2=0;
		}
	}
	sort(a+1,a+n+1);
	if(flag1)
	{
		LL sum=0;
		for(int i=1;i<=n/2;++i)
		{
			sum+=a[i].v1;
		}
		print(sum);
		return ;
	}
	LL sum=0;
	for(int i=1;i<=n/2;++i)
	{
		sum+=a[i].v1;
		sum+=a[i+(n/2)].v2;
	}
	print(sum);
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--)
	{
		solve();
	}
	return 0;
}