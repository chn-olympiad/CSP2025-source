// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

typedef long long ll;

struct EDGE
{
	int u,v;
	ll w;
};

int n,m,k;
int cnt=0;
int fa[(int)1e4];
EDGE e[(int)3e6];
ll cost[(int)3e6];

class FastIn
{
	#define maxLen (1<<20)
	int len=0;
	char Buf[maxLen];
	int p=0;
	int gc()
	{
		if(p>=len||Buf[p]==EOF) len=fread(Buf,sizeof(char),maxLen,stdin),p=0;
		return Buf[p++];
	}
public:
	int read()
	{
		ll res=0;
		char ch=gc();
		while(ch<'0'||ch>'9') ch=gc();
		while(ch>='0'&&ch<='9') res=(res<<1)+(res<<3)+(ch^48),ch=gc();
		return res;
	}
};


ll query(int x)
{
	if(fa[x]!=x) fa[x]=query(fa[x]);
	return fa[x];
}

ll calc(int info)
{
	ll res=0;
	int checked=n;
	for(int i=0;i<k;i++)
	{
		if((1<<i)&info) res+=cost[i+1],++checked;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=cnt&&checked>0;i++)
	{
		if(e[i].u>n)
		{
			if(((1<<(e[i].u-n-1))&info)==0) continue;
		}
		if(query(e[i].u)!=query(e[i].v))
		{
			res+=e[i].w;
			fa[query(e[i].u)]=query(e[i].v);
		}
	}
	return res;
}

int main()
{
#ifndef LOCAL_TEST
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
#endif
	FastIn in;
	n=in.read(),m=in.read(),k=in.read();
	cnt=m;
	for(int i=1;i<=m;i++)
	{
		e[i].u=in.read(),e[i].v=in.read(),e[i].w=in.read();
//		if(i>=59000) cout<<i<<"\n";
	}
		
	for(int i=1;i<=k;i++)
	{
		cost[i]=in.read();
		for(int j=1;j<=n;j++)
		{
			ll w;
			w=in.read();
			e[++cnt]={i+n,j,w};
		}
	}
	sort(e+1,e+1+cnt,[](EDGE a,EDGE b){
		return a.w<b.w;
	});
//	for(int i=1;i<=cnt;i++)
//		cout<<e[i].u<<" " <<e[i].v<<" "<<e[i].w<<"\n";
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)
	{
		ans=min(calc(i),ans);
	}
	cout<<ans;
	return 0;
}

