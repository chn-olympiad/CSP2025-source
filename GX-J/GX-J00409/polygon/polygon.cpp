#include <cstdio>
#include <algorithm>

#define MAX_N 5005
#define MOD 998244353

using namespace std;

int n, a[MAX_N], ans=0;

int chosen[MAX_N];

bool check(int num) {
    int sum = 0;
    for (int i = 0;i < num - 1;++i) {
        sum += a[chosen[i]];
        if (sum > a[chosen[num - 1]]) return true;
    }
    return false;
}

void solve(int num, int pos) {
    if (num == pos && check(num)) {
        ans++;
        ans %= MOD;
        return;
    }
    int backv = 0;
    if (pos != 0) backv = chosen[pos - 1] + 1;
    for (int i = backv;i < n;++i) {
        chosen[pos] = i;
        solve(num, pos + 1);
    }
}

#define CACHE_SIZE 1000 
int cache[CACHE_SIZE][CACHE_SIZE];
int calc_choose_b_in_a(int a, int b) {
    if (b == 1) return a % MOD;
    if (a < CACHE_SIZE && b < CACHE_SIZE && cache[a][b] != 0) return cache[a][b];
    int sum = 0;
    for (int i = b - 1;i <= a - 1;++i) {
        sum += calc_choose_b_in_a(i, b - 1);
        sum %= MOD;
    }
    if (a < CACHE_SIZE && b < CACHE_SIZE) cache[a][b] = sum % MOD;
    return sum % MOD;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    bool is_all_1 = true;

    scanf("%d", &n);
    for (int i = 0;i < n;++i) {
        scanf("%d", &a[i]);
        is_all_1 &= (a[i] == 1);
    }

    if (!is_all_1) {
        sort(&a[0], &a[n]);
        for (int i = 3; i <= n; ++i) {
            solve(i, 0);
        }
        printf("%d\n", ans);
    } else {
        int sum = 0;
        for (int i = 3;i <= n;++i) {
            sum += calc_choose_b_in_a(n, i);
            sum %= MOD;
        }
        printf("%d\n", sum);
    }

    return 0;
}

// Is the part points is easy to get? It is so strange that why I can get 52 points easily.
// So I am so afraid that the first prize will be hard to get.

// I remember that somebody sent hundreds of files into ftp server in CSPJ last year. So that many tester failed to send their codes. It is a actually bad active!
// In my opinion, each qustions are so easy that I am worried about is there some special mistakes that I made.
// Good luck.

// Check List:
// freopen -- ok
// direction and file's name -- ok

// someone that sat in my left is named Jiahao. Yes, it is Jiahao that you are thinking. Now(11:57) he is exit virtual machine and run huorong. OH MY MKS!
// By the way, VSCODE is useful! I have seen someone is using Sublime and someone is using Emacs.