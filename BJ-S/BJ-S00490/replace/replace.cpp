#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll b1 = 131;
const ll m1 = 19260817;
const ll invb1 = 11762331;
const ll b2 = 163;
const ll m2 = 1000000007;
const ll invb2 = 116564418;
inline ll fpow(ll b, ll n, ll m)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1) ans *= b, ans %= m;
        b *= b, b %= m;
        n >>= 1;
    }
    return ans;
}
ll n, q;
string is1, is2;
struct hstring
{
    string ori;
    ll len;
    vector<ll> h1, h2;
    void gen()
    {
        len = ori.size();
        h1.resize(len + 1);
        h2.resize(len + 1);
        h1[0] = h2[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            h1[i] = h1[i - 1] * b1 % m1;
            h1[i] += ori[i - 1];
            h1[i] %= m1;
            h2[i] = h2[i - 1] * b2 % m2;
            h2[i] += ori[i - 1];
            h2[i] %= m2;
        }
    }
    pair<ll, ll> substr(ll a, ll b)
    {
        if (a < b) return {0, 0};
        ll hi1 = h1[b], lo1 = h1[a - 1] * fpow(b1, b - a + 1, m1) % m1;
        ll r1 = (hi1 - lo1 + m1) % m1;
        //r1 = r1 * fpow(invb1, a - 1, m1) % m1;
        //cout << hi1 << '-' << lo1 <<'=' << r1 <<endl;
        ll hi2 = h2[b], lo2 = h2[a - 1] * fpow(b2, b - a + 1, m2) % m2;
        ll r2 = (hi2 - lo2 + m2) % m2;
        //r2 = r2 * fpow(invb2, a - 1, m2) % m2;
        //cout << hi2 << '-' << lo2 <<'=' << r2 <<endl;
        return {r1, r2};
    }
    string substr_s(ll a, ll b)
    {
        return ori.substr(a - 1, b - a + 1);
    }
} s1[200005], s2[200005], t1, t2;
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%lld%lld", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> is1 >> is2;
        s1[i].ori = is1;
        s1[i].gen();
        s2[i].ori = is2;
        s2[i].gen();
    }
    while (q--)
    {
        cin >> is1 >> is2;
        if (is1.length() != is2.length())
        {
            printf("0\n");
            continue;
        }
        t1.ori = is1;
        t1.gen();
        t2.ori = is2;
        t2.gen();
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            ll l = s1[i].len;
            for (int j = 1; j <= t1.len - l + 1; j++)
                if (t1.substr_s(1, j - 1) == t2.substr_s(1, j - 1) && t1.substr_s(j + l, t1.len) == t2.substr_s(j + l, t1.len))
                if (t1.substr_s(j, j + l - 1) == s1[i].substr_s(1, l))
                if (t2.substr_s(j, j + l - 1) == s2[i].substr_s(1, l))
                    cnt++;
        }
        printf("%lld\n", cnt);
    }
    return 0;
}
