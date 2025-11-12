#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char s[501];
int c[501];
int a[501];
bool check()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt >= c[a[i]]) cnt++;
        else if (!(s[i] - '0')) cnt++;
    }
    return n - cnt >= m;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> c[i], a[i] = i;
    int ans = 0;
    do
    {
        ans += check();
    } while(next_permutation(a+1, a+n+1));
    cout << ans << endl;
    return 0;
}