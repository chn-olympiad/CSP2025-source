#include<algorithm>
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
	const int const1=600;
	const int mod=998244353;
	std::string s;
	int c[const1],p[const1];
	void solve()
	{
		int i,n,m,gu(0),ss(0),ans(0);
		read(n,m);
		std::cin>>s;
		for(i=1;i<=n;++i) read(c[i]);
		for(i=1;i<=n;++i) p[i]=i;
		while(std::next_permutation(p+1,p+n+1))
		{
			gu=0;
			ss=0;
			for(i=1;i<=n;++i)
			{
				if(gu>=c[p[i]]) ++gu;
				else
				{
					if(s[i-1]=='1') ++ss;
					else ++gu;
				}
			}
			if(ss>=m) ++ans;
		}
		write(ans);
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	Sol::solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
