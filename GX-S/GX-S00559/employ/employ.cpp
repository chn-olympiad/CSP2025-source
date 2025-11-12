#include <iostream>
#include <algorithm>
#define ll long long
//#define a first
//#define b second
using namespace std;
const int N = 505;
const int mod = 998244353;
ll n, m, ans, a[N];
string s;
void main1()
{
    ll ans = 1;
    for (int i = 2; i <= n; i++)
        ans = ans * i % mod;
    cout << ans << endl;
}
void main2()
{
    ll num[N];
    for (int i = 1; i <= n; i++)
        num[i] = i;
    do
    {
        ll sum = 0, cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '1' && cnt < a[num[i]])
                sum++;
            else
                cnt++;
        }
        ans += sum >= m;
    } while (next_permutation(num + 1, num + n + 1));
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //if (s == string(s.size(), '1'))
    //    main1();
    //else
        main2();
    return 0;
}
