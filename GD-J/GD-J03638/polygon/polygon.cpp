#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353, N = 5010;

bool vis[N];
ll n, ans = 0;

ll dp[N][N][2];
ll choose[N];


bool cmp(int a, int b) {
    return a > b;
}

int main() {
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n, a, b ,c;
    cin >> n;
    if (n < 3)
        cout << 0;
    else if (n == 3)
    {
        cin >> a >> b >> c;
        if (a + b + c > 2 * max(a, max(b, c)))
            cout << 1;
        else
            cout << 0;
    }
    else
    {
        cout << 1;
    }
}