// T4 baoli: DFS check         time:O(2**n)
/*
now 1 ~ 10     40pts
15 ~ 20       24pts
all: 64pts
11~14 21~25       TLE
*/
// C
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
#include <cwchar>
#include <cwctype>

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

// C++ 11
#include <array>
#include <atomic>
#include <chrono>
#include <codecvt>
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
using namespace std;

using LL = long long;

/*
M:
998, 244, 353
998244353
998'244'353
*/
namespace ABCDEFG {
constexpr int M = 998'244'353;

int n, a[5010];
LL ans;
// int  s[5010];

void dfs(int step, int sum, int maxn, int m) {
    if (step > n) {
        if ( m >= 3 && sum > 2 * maxn){
            ++ans;
            ans%=M;
        }
        return;
    }
    // step xuanbuxuan?
    
    // xuan
    dfs(step + 1, sum + a[step], max(maxn, a[step]), m + 1);
    // not xuan
    dfs(step + 1, sum, maxn, m);
    return;
}
long long p(long long a, long long n) {
    if (n == 0LL) {return 1LL;}
    if (n == 1LL) {return a;}
    if (n % 2 == 0) {
        long long temp = p(a, n / 2);
        return temp * temp%M;
    }
    long long temp = p(a, n / 2);
    return temp * temp * a % M;
    // %M    !!!!!!!!   do not forget!
}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    
    scanf("%d", &n);
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] !=1) {flag=false;}
    }
    if (flag) {
        // a[i] is all = 1
        // all is OK!
        if(n == 3) {
            printf("1\n");
        } else {
            ans = p(2LL, 1LL * n) - 1LL - 1LL*n - 1LL * n * (n -1) / 2;
            ans%=M;
            printf("%lld\n",ans);
        }
        return 0;
    }
    dfs(1, 0, -1, 0);
    printf("%lld\n", ans);
    return 0;
}
}

int main() {

    return ABCDEFG::main();
}
/*
keyi bu(not) lianxu
AAAAAAA!
*/

/*
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        // printf("%d", s[i]);
    }
    LL ans = 0LL;
    for (int i = 1; i <= n - 2; ++i) {
        for (int j = i + 2; j <= n; ++j) {
            // i ~ j check
            int t = s[j] - s[i - 1]; // qianzhuihe i ~ j
            int maxn = -1;
            for (int k = i; k <= j; ++k) {
                maxn = max(maxn, a[k]);
            }
            if (t > maxn * 2) {
                printf("%d %d\n", i, j);
                ++ans;
                ans %= M;
            }
        }
    }
    printf("%lld\n", ans);
    */