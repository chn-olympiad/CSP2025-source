#include <bits/stdc++.h>
#define int long long
#define gc getchar()
using namespace std;

int rd()
{
    int x = 0, f = 1;
    char c = gc;
    for(; !isdigit(c); c = gc) if(c == '-') f = -1;
    for(; isdigit(c); c = gc) x = x * 10 + (c ^ 48);
    return x * f;
}

int n, k;
int a[500005], p, ans;

set <int> s;

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    n = rd(), k = rd();
    for(int i = 1; i <= n; i++) a[i] = a[i-1] ^ rd();
    s.insert(0);
    for(int i = 1; i <= n; i++)
    {
        if(s.count(a[i] ^ k)) s.clear(), ans++;
        s.insert(a[i]);
    }
    cout << ans;
    return 0;
}
