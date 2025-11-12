#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gets() {
    int input = getchar();
    ll ret = 0, neg = 1;
    while(input < '0' || input > '9') {
        if(input == '-') {
            neg = -1;
        }
        input = getchar();
    }
    while(input >= '0' && input <= '9') {
        ret = input - '0' + ret * 10;
        input = getchar();
    }
    return ret * neg;
}
void puts(ll output) {
    if(output < 0) {
        putchar('-');
        output = - output;
    }
    if(output > 9) {
        puts(output / 10);
    }
    putchar(char(output % 10 + '0'));
}
const int N = 510;
int n, m, tot, v[N], c[N], pre[N];
ll mod = 998244353, ind[N], inp[N];
ll qp(ll a, ll b) {
    ll ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
ll comb(ll a, ll b) {
    if(b > a) return 0LL;
    return ind[a] * inp[a - b] % mod * inp[b] % mod;
}
ll dfs(int i, int j) {
    if(i == n + 1) {
        if(n - j >= m) {
            return 1;
        }
        return 0LL;
    }
    // 第i人，之前不过j个
    int pass = i - j;
    int lt = pre[j] - j, rt = n - pre[j] - pass;
    // 剩lt不能过，rt能过
    ll ret = 0LL;
    if(lt) ret = (ret + dfs(i + 1, j + 1) * lt) % mod;
    if(rt) ret = (ret + dfs(i + 1, j) * rt) % mod;
    return ret;
}
int main() {
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ind[0] = inp[0] = 1;
    for(int i = 1; i < N; i ++) {
        ind[i] = ind[i - 1] * i % mod;
        inp[i] = inp[i - 1] * qp(i, mod - 2) % mod;
    }
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '0') {
            tot ++;
        }
    }
    for(int i = 1; i <= n; i ++) {
        cin >> v[i];
        c[v[i]] ++;
    }
    pre[0] = c[0];
    for(int i = 1; i < N; i ++) {
        pre[i] = pre[i - 1] + c[i];
    }
    cout << dfs(1, 0) << '\n';
    return 0;
}
//g++ -g employ.cpp -o e -std=c++14 -O2 -Wall -Wextra -Wconversion -Wshadow -fsanitize=address,undefined
