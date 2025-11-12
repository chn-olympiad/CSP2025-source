#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int N = 1000005;
const int inf = 0x3f3f3f3f;
char s[N];
void work()
{
    cin >> (s + 1);
    int n = strlen(s + 1);
    vector<int> a;
    for (int i=1;i<=n;i++)
        if (s[i] >= '0' && s[i] <= '9')
            a.pb(s[i] - '0');
    sort(a.begin(), a.end());
    for (int i=a.size()-1;i>=0;i--)
        cout << a[i];
    cout << '\n';
}
int main()
{
    freopen("number.in", "r", stdin);freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int _T = 1;
    //cin >> _T;
    while (_T --)
        work();
    return 0;
}