#include<bits/stdc++.h>
using namespace std;
constexpr long long N=1e5,M=1e5,V=1e18;
long long n,m;
struct bit
{
	inline int lb(int x){return x&-x;}
	long long sz;
	int c[N+5];
	bit(long long n)
	{
		fill_n(c,n+2,0);
		sz=n;
	}
	void add(int x,long long k)
	{
		for(;x<=sz;x+=lb(x))
		{
			c[x]+=k;
		}
	}
	long long qry(int x)
	{
		long long ret=0;
		for(;x>0;x-=lb(x))
		{
			ret+=c[x];
		}
		return ret;
	}
};
int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	
	return 0;
}

