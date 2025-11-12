#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define int long long
const int N = 5e5+7;

int n, k;
int a[N], vis[N];
int ans;

signed main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ans = n;
    if (k == 0)
    {
        cout << n/2;
    }




    return 0;
}
