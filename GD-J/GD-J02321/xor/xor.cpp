#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 50, V = (1 << 21) + 50;

int n, k, a[maxn], b[maxn], f[maxn], mx[maxn], pre[maxn], lst[V];

int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= (1 << 21); i++) lst[i] = -1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
        pre[i] = lst[b[i] ^ k];
        lst[b[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        if(pre[i] != -1) f[i] = mx[pre[i]] + 1;
        mx[i] = max(mx[i - 1], f[i]);
    }
    cout << mx[n];
    return 0;
}