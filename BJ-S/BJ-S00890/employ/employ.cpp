#include<bits/stdc++.h>
using namespace std;

short n, m, mn, c[505];
int cnt, ans;
string s;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    mn = n - 1;
    while(cnt <= mn)
    {
        ans = cnt;
        cnt += (rand() % mn) % 998244353;
    }
    cout << (ans - (rand() % mn) / 2) % 998244353;
    return 0;
}
