// "bit operator"  must: ()    !!!!!!!!!
/*
5pts/test
1 2 3 4 5 13              30pts
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
namespace ABCDEFG {
constexpr int N = 500010;
int n, k, a[N], s[N], ans;

void dfs(int step, int maxs) {
    if (step == n) {
        return;
    }
    for (int i = step + 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j){
            if ((s[j] ^ s[i -1]) == k) {
                ans = max(ans, maxs + 1);
                dfs(j, maxs + 1);
            }
        }
    }


    return;
}

int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    scanf("%d%d", &n, &k);
    bool flagA = true, flagB = true;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = (s[i - 1] ^ a[i]);
        if (a[i] != 1) {
            flagA = false;
        }
        if (a[i] != 1 && a[i] != 0) flagB = false;
    }
    // test1
    if (n == 1){
        if (a[1] == k) {printf("1\n");}
        else {printf("0\n");}
        return 0;
    }
    if (n == 2) {
        int temp = 0;
        if (a[1] == k) {++temp;}
        if (a[2] == k) {++temp;}
        temp = max(temp, int(s[2] == k));
        printf("%d\n", temp);
        return 0;
    }
    // end test1
    if (flagA && (k == 0)) {
        // special A
        printf("%d\n", n / 2);
        return 0;
    }
    if (flagB){
        // special B
        if (k==1) {
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 1)++ans;
            }
            printf("%d\n", ans);
            return 0;
        } else {
            // k == 0
            for (int i = 1; i <= n; ++i) {
                if (a[i] == 0) ++ans;
                if (a[i] == 1) {
                    if (a[i + 1] ==1) {
                        ++ans;
                        i += 1;
                    }
                }
            }
            printf("%d\n", ans);
        }return 0;
    }    
    // DFS
    dfs(0, 0);
    printf("%d\n", ans);
    return 0;
}
} 

int main() {

    return ABCDEFG::main();
}