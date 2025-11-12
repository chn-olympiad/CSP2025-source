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

const int N=510;
const int MOD=998244353;

int n,m,c[N],cnt;
char s[N];
LL ans;

bool cmp(int X,int Y)
{
	return X>Y;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();
	m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		c[i]=read();
		if(c[i])
		{
			++cnt;
		}
	}
	sort(c+1,c+n+1,cmp);
	if(cnt>=m)
	{
		ans=1;
		for(int i=1;i<=cnt;++i)
		{
			ans=ans*i%MOD;
		}
		print(ans);
	}
	else
	{
		puts("0");
	}
	return 0;
}