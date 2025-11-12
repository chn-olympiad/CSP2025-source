#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define ld long double

inline int read()
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

inline void prt(int x)
{
	if (x==0)
	{
		putchar('0');
		return;
	}
	if (x<0) x=-x,putchar('-');
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

const int maxn=5e5+10;

int n,k,ans;
int a[maxn],pre[maxn],dp[maxn];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	n=read();k=read();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		pre[i]=(pre[i-1]^a[i]);
	}
	dp[1]=(a[1]==k?1:0);
	for (int i=2;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for (int j=1;j<=i;j++)
		{
			if ((pre[i]^pre[j-1])==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
	}
	prt(dp[n]);putchar('\n');
	
	return 0;
}
