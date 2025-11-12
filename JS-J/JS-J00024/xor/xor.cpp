#include <bits/stdc++.h>
using namespace std;

int n;
unsigned int k;
unsigned int a[500005];
map<unsigned int, unsigned int> mp;
int l[500005], r[500005], cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    mp[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        if(mp.find(a[i] ^ k) != mp.end()) r[++cnt] = i, l[cnt] = mp[a[i] ^ k] + 1;
        mp[a[i]] = i;
    }
    int lr = 0, ans = 0;
    for(int i = 1; i <= cnt; i++) {
        if(l[i] > lr) {
            lr = r[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}
