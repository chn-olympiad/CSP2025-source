#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, a[5005], ans;
int j1(int he)
{
    int zong = 1;
    for (int i = 2; i <= he; i++) zong = zong*i%mod;
    return zong;
}
int j2(int l, int r)
{
    for (int i = l+1; i <= r; i++) l = l*i%mod;
    return l;
}
int c(int shu, int qv)
{
    return j2(qv+1, shu)/j1(shu-qv)%mod;
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n < 3)
    {
        cout << 0;
    }
    else if (n == 3)
    {
        int sum = a[1]+a[2]+a[3];
        int maxa = max(a[1], max(a[2], a[3]));
        if (sum > maxa*2) cout << 1;
        else cout << 0;
    }
    else
    {
        int ans = 1;
        for (int i = 3; i < n; i++) ans = (ans+c(n, i))%mod;
        cout << ans;
    }
    return 0;
}
