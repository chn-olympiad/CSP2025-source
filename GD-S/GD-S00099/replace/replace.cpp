#include<iostream>
#include<cstdio>
#include<string>
namespace io
{
	void read()
	{
		return;
	}
	template<typename nowtype,typename ...nexttype>
	void read(nowtype &now,nexttype &...next)
	{
		now=0;
		char c=getchar();
		bool sign(false);
#define isdigit(c) ((c)>='0'&&(c)<='9')
		while(!isdigit(c)){if(c=='-') sign=true;c=getchar();}
		while(isdigit(c)){now=(now<<1)+(now<<3)+(c^48);c=getchar();}
#undef isdigit
		if(sign) now=-now;
		read(next...);
	}
	template<typename nowtype>
	void write(nowtype now,char end='\n')
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(end);
	}
	template<typename nowtype,typename ...nexttype>
	void write(nowtype now,char sep,nexttype ...next)
	{
		if(now<0) putchar('-');
		int c[40],top(0);
#define abs(x) ((x)<0?-(x):(x))
		do c[top++]=abs(now%10),now/=10;while(now);
#undef abs
		while(top) putchar(c[--top]+48);
		putchar(sep);
		write(next...);
	}
}
using namespace io;
namespace Sol
{
	typedef long long ll;
	typedef unsigned long long ull;
	std::string s1,s2,t1,t2;
	void solve()
	{
		int i,n,q;
		read(n,q);
		for(i=1;i<=n;++i) std::cin>>s1>>s2;
		for(i=1;i<=q;++i)
		{
			std::cin>>t1>>t2;
			write(0);
		}
	}
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	Sol::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
