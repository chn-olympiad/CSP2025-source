#include<bits/stdc++.h>
using namespace std;

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

inline void write(int x)
{
	if(x>9)
	{
		write(x/10);
	}
	putchar(char(x%10+48));
}

inline void print(int x)
{
	if(x<0)
	{
		x=-x;
		putchar('-');
	}
	write(x);
	puts("");
}



int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n=read();
	int q=read();
	
	for(int i=1;i<=q;++i)
	{
		print(0);
	}
	
	
	
	
	return 0;
}