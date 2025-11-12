#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n;
    long long ans = 1;
    for(int i = 1;i <= n;i++)
    {
        ans *= i;
        ans %= 998244353;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
