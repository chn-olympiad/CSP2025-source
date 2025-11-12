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

/*
维护三个集合，
每次第i个人扔到喜好度最高的集合里
若无法加入：
	1. 取出集合中喜好度最低的人，记为j
	2. 显然，若有一个集合接近满人，则另外两个集合一定都可以加人
	3. 把当前i最大的满意度+j次大的满意度，
	i次大的满意度和j最大的满意度进行比较， 根据大小决定换谁。
	4. 若一个人满意度相同， 扔到人数更少的集合。
*/


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

FastIn in;
pair<ll,int> like[(int)1e5+10][3];

void work() {
	int n=in.read();
	for(int i=1; i<=n; i++) {
		for(int j=0; j<3; j++)
			like[i][j].first=in.read(),like[i][j].second=j;
		sort(like[i],like[i]+3,
		[](pair<ll,int> a,pair<ll,int> b) {
			return a.first>b.first;
		}
		    );
	}
	ll ans=0;
	priority_queue<pair<ll,int>,
	               vector<pair<ll,int>>,
	               greater<pair<ll,int>>> club[3];
	for(int i=1; i<=n; i++) {
		if((int)club[like[i][0].second].size()+1<=n/2) {
			ans+=like[i][0].first;
			club[like[i][0].second].
			push(make_pair(like[i][0].first-like[i][1].first,i));
		} else {
			pair<ll,int> mn=club[like[i][0].second].top();
			if(mn.first>like[i][0].first-like[i][1].first)
				ans+=like[i][1].first;
			else {
				club[like[i][0].second].pop();
				club[like[i][0].second].push(
				    make_pair(like[i][0].first-like[i][1].first,i));
				ans-=like[mn.second][0].first;
				ans+=like[mn.second][1].first;
				ans+=like[i][0].first;
			}
		}
	}
	cout<<ans<<"\n";
}

int main() {
#ifndef LOCAL_TEST
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#endif
	int t=in.read();
	while(t--)
		work();
	return 0;
}

