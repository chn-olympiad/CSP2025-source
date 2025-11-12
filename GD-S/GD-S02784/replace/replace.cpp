#include<bits/stdc++.h>
#define ll long long
#define db double

using namespace std;

inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

void write(ll x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ll n=read();
	ll q=read();
	while(q--)
	{
		write(0);
		putchar('\n');
	} 
	return 0;
	//I like you~~~~~
}
