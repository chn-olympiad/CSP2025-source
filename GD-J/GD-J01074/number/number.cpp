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

const int maxn=1e6+10;

string s;
int n,m;
int a[maxn];

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	cin>>s;
	n=s.length();
	for (int i=0;i<n;i++)
	{
		if ('0'<=s[i]&&s[i]<='9')
		{
			a[++m]=s[i]-'0';
		}
	}
	sort(a+1,a+m+1,cmp);
	for (int i=1;i<=m;i++)
	{
		prt(a[i]);
	}
	putchar('\n');
	
	return 0;
}
