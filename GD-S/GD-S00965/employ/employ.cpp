#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

int read()
{
	int x=0,f=1;
	char ch=' ';
	while (ch<'0'||ch>'9')
	{
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

void prt(int x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) putchar('-'),x=-x;
	int stac[20],top=0;
	while (x)
	{
		stac[++top]=x%10;
		x/=10; 
	}
	while (top)
	{
		putchar(stac[top--]^48);
	}
	return;
}

const int maxn=500+10;
const ll mod=998244353;

int n,m;
bitset<maxn>s;
int c[maxn],p[maxn];
ll ans;
int mc,zr;
bool sz,cz;

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	n=read();m=read();
	for (int i=1;i<=n;i++)
	{
		char ch=' ';
		while (ch!='0'&&ch!='1') ch=getchar();
		s[i]=ch-'0';
		if (!s[i]) sz=true,zr=i;
	}
	for (int i=1;i<=n;i++)
	{
		c[i]=read();
		p[i]=i;
		mc=max(mc,c[i]);
		if (!c[i]) cz=true;
	}
	if (n<=18)
	{
		do
		{
			int died=0,realm=0;
			for (int i=1;i<=n;i++)
			{
				if (died>=c[p[i]])
				{
					died++;
					continue;
				}
				if (!s[i])
				{
					died++;
				}
				else
				{
					realm++;
					if (realm>=m)
					{
						ans=(ans+1)%mod;
						break;
					}
				}
			}
		}while (next_permutation(p+1,p+n+1));		
	}
	else
	{
		ans=1;
		for (int i=2;i<=m;i++)
		{
			ans=ans*i%mod;
		}
		if (m==n&&(sz||cz)) ans=0;
	}
	
	prt(ans%mod);putchar('\n');
	
	return 0;
}
