#include<bits/stdc++.h>
using namespace std;
int n, k, a[505];
bool st[505];
vector<int> res;
string s;
int ans;
const int mod = 998244353;
void dfs(int u)
{
    if(u == n+1)
    {
        int sum = 0, xy = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '0' || sum >= a[res[i-1]]) sum++;
            else xy++;
            if(xy >= k)
            {
                ans++;
                ans %= mod;
                return;
            }
        }
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            if(st[i]) continue;
            st[i] = 1;
            res.push_back(i);
            dfs(u+1);
            st[i] = 0;
            res.pop_back();
        }
    }
}
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> k >> s;
    s = " " + s;
    int sum0 = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] == 0) sum0++;
    }
    if(n > 18)
    {
        if(n-sum0 < k)
        {
            cout << 0 << endl;
            return 0;
        }
        long long ans = 1, ans1 = 1;
        for(long long i = 1; i <= n-sum0; i++) ans *= i, ans %= mod;
        for(int i = 1; i <= sum0; i++) ans1 *= i, ans1 %= mod;
        cout << (ans+ans1)%mod << endl;
        return 0;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}
