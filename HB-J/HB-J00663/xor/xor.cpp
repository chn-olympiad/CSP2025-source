#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, k;
int a[N];
int l[N];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll ans = 0;
    int st = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j >= st; j--)
        {
            l[j] = l[j] ^ a[i];
            if(l[j] == k)
            {
                ans = ans + 1;
                st = i + 1;
            }
        }
    }
    cout << ans;
    return 0;
}
