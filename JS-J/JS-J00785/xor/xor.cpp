#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll a[N];
bool vis[N] = {0};
int sum(int x, int y)
{
    for(int i = x; i <= y; i++)
        if(vis[i]) return -1;
    int ans = 0;
    for(int i = x; i <= y; i++)
        ans  = ans ^ a[i];
    return ans;
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] == k) ans++, vis[i] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            if(sum(i, j) == k)
            {
                ans++;
                for(int p = i; p <= j; p++)
                    vis[p] = 1;
            }
        }
    cout << ans << endl;
    return 0;
}
