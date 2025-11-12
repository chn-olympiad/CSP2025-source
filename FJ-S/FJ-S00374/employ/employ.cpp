#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 505, mod = 998244353;
int n, m, c[N], cnt[N];
ll ans = 1;
vector<int> s;

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1, x; i <= n; i++)
    {
        cin >> x;
        if(x) s.push_back(x);
    }
    for(int i = 1, y; i <= n; i++)
    {
        cin >> y;
        for(int j = 0; j < s.size(); j++)
        {
            int u = s[j];
            if(u-j <= y) c[i] = j+1, cnt[j+1]++;
        }
    }
    if(s.size() < m) 
    {
        cout << 0 << endl;
        return 0;
    }
    if(m == n)
    {
        for(int i = 1; i <= n; i++)
            if(cnt[i] >= i) ans = ans*(cnt[i]-i+1);
            else ans = 0;
        cout << ans << endl;
        return 0;
    }

    return 0;
}