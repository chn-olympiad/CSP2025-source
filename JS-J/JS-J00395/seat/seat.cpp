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
// n, m   ->      m, n!!!!!!!!!!
namespace ABCDEFG{
int a[1000];

int main() {
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n * m; ++i) {
        scanf("%d", &a[i]);
    }
    int q = a[1];
    sort(a + 1, a + n * m + 1);
    int p = lower_bound(a + 1, a + n * m + 1, q) - a;
    p = n * m + 1 - p;
    // printf("%d\n", p);
    int c = (p + n - 1) / n, r = p % n;
    if (r == 0) {r = n;}
    if (c % 2 == 0) {
        r = n + 1 - r;
    }
    printf("%d %d\n", c, r);
    return 0;
}
}
int main() {

    return ABCDEFG::main();
}
/*
panduan lie first
ceil()
*/