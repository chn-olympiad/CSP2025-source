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

const int maxmn=10+5;

int n,m,c,r;

struct Contestant
{
	int score,id;
}ct[maxmn*maxmn];

bool cmp(Contestant a,Contestant b)
{
	return a.score>b.score;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	n=read();m=read();
	for (int i=1;i<=n*m;i++)
	{
		ct[i].score=read();
		ct[i].id=i;
	}
	sort(ct+1,ct+n*m+1,cmp);
	
	for (int i=1;i<=n*m;i++)
	{
		if (ct[i].id==1)
		{
			c=(i-1)/n+1;
			
			if (c&1)
			{
				r=i%n;
				if (r==0) r=n;
			}
			else
			{
				r=n-(i%n)+1;
				if (r==n+1) r=1;
			}
			
			prt(c);putchar(' ');prt(r);putchar('\n');
			
			return 0;
		}
	}
}
