#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=5e6+5;
const unsigned long long P=1e9+7,O=998244353;
int n,Q;
char x[M],y[M];
map<pair<unsigned long long,unsigned long long>,int>mapp;
unsigned long long dp[30];
int read()
{
	char c=getchar();
	int x=0;
	while(c<'0'||c>'9')c=getchar();
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x;
}
void write(unsigned long long x)
{
	if(x<9)
	{
		putchar(x+'0');
		return;
	}
	write(x/10);
	putchar(x%10+'0');
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	Q=read();
	for(int i=0;i<26;i++)dp[i]=i+1;
	for(int i=1;i<=n;i++)
	{
		unsigned long long a=0,b=0;
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z')
		{
			a=a*P+dp[c-'a'];
			c=getchar();
		}
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z')
		{
			b=b*P+dp[c-'a'];
			c=getchar();
		}
		mapp[make_pair(a,b)]++;
	}
	while(Q--)
	{
		int lex=0,ley=0,le,ans=0;
		char c=getchar();
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z')
		{
			x[++lex]=c;
			c=getchar();
		}
		while(c<'a'||c>'z')c=getchar();
		while('a'<=c&&c<='z')
		{
			y[++ley]=c;
			c=getchar();
		}
		if(lex!=ley)
		{
			write(0);
			putchar('\n');
			continue;
		}
		le=lex;
		int cnt1=0,cnt2=0;
		for(int i=le;i>=1;i--)
		{
			if(x[i]!=y[i])
			{
				cnt1=i;
				break;
			}
		}
		for(int i=1;i<=le;i++)
		{
			if(x[i]!=y[i])
			{
				cnt2=i;
				break;
			}
		}
		for(int i=1;i<=cnt2;i++)
		{
			unsigned long long X=0,Y=0;
			for(int j=i;j<=le;j++)
			{
				X=X*P+dp[x[j]-'a'];
				Y=Y*P+dp[y[j]-'a'];
				if(j>=cnt1)ans+=mapp[make_pair(X,Y)];
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
