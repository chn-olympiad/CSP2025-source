#include<bits/stdc++.h>
using namespace std;
#define int long long int
constexpr int MOD = 998244353;
int n;
vector<int>a;
int num[5005],ans = 0;
string operator * (string s,int t)
{
    int jw = 0;
    for(int i = 0;i < s.size() || jw;i++)
    {
        jw += t * (s[i] - '0');
        s[i] = jw % 10 + '0';
        jw /= 10;
    }
    return s;
}
string operator + (string s,string t)
{
    for(int i = 0;i < s.size() || i < t.size();i++)
    {
        s[i] += t[i] - '0';
        if(s[i] > '9') s[i] -= 10,s[i + 1]++;
    }
    return s;
}
void fix(int m)
{
    int sum = n * (n - 1) * (n - 2) / 6;num[3] = sum;
    for(int i = 4;i <= m;i++)
    {
        sum = sum * (n - i + 1) / i;
        sum = sum % MOD;
        num[i] = sum;
    }
}
bool check(int state)
{
    int sum = 0,maxx = 0,num;
    for(int i = 0;i < n;i++)
    {
        if(state % 2) sum += a[i],maxx = max(maxx,a[i]),num++;
        state >>= 1;
    }
    return num >= 3 && sum > maxx << 1;
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n;
    bool way = true;
    for(int i = 1;i <= n;i++)
    {
        int k;cin >> k;
        a.push_back(k);
        if(k > 1) way = false;
    }
    if(way)
    {
        fix((n + 2) >> 1);
        for(int i = 3;i <= n;i++)
        {
            if(i > n - i) ans += num[n - i];
            else ans += num[i];
            ans %= MOD;
        }
    }
    else
    {
        for(int i = 7;i < 1 << n;i++)
        {
            ans += check(i);
            ans %= MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}