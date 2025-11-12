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

const ll MOD=998244353;

ll ans=0;

int n,m;
string str;
ll c[510];
ll res[510];
bitset<510> used;
int sum[510];

void dfs(int x)
{
	if(x>m)
	{
		for(int i=1;i<=n;i++)
		{
			if(sum[i]>c[res[i]]) return;
		}
		ans=(ans+1)%MOD;
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(used[i]) continue;
		used[i]=1;
		res[x]=i;
		dfs(x+1);
		used[i]=0;
	}
}

int main()
{
#ifndef LOCAL_TEST
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+str[i-1]=='0';
	for(int i=1;i<=m;i++)
	cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

