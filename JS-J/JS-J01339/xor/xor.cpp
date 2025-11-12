#include <bits/stdc++.h>
using namespace std;
long long n, k;
long long a[500010];
long long lst[500010];
long long dp[500010];
unordered_map <long long, long long> mp;
int main () {
    freopen ("xor.in", "r", stdin);
    freopen ("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    lst[1] = a[1];
    for (long long i = 2; i <= n; i++)
        lst[i] = lst[i - 1] ^ a[i];
    for (long long i = 1; i <= n; i++)
        mp[lst[i]]++;
    dp[0] = 0;
    long long temp = 0;
    for (long long i = 1; i <= n; i++) {
        mp[lst[i]]--;
        if (mp[lst[i]] == 0)
            mp.erase(lst[i]);
        dp[i] = dp[i - 1];
        if ((temp ^ a[i]) == k) {
            dp[i]++;
            temp = 0;
        }
        else {
            long long x = (k ^ a[i]);
            long long c = (x ^ lst[i]);
            if (mp.count(c) == true)
                temp = a[i];
            else {
                long long u = (k ^ (a[i] ^ temp));
                long long v = (u ^ lst[i]);
                if (mp.count(v) == true)
                    temp = (a[i] ^ temp);
                else
                    temp = 0;
            }
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
