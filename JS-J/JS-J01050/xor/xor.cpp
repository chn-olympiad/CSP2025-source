#include<bits/stdc++.h>
using namespace std;
#define int long long int
int xo(int a,int b)
{
    bool _a[25],_b[25];
    int k = 0;
    while(a)
    {
        _a[k] = a % 2;
        k++;
        a >>= 2;
    }
    k = 0;
    while(b)
    {
        _b[k] = b % 2;
        k++;
        b >>= 1;
    }
    for(int i = 0;i < 25;i++)
    {
        _a[i] = (_a[i] != _b[i]);
    }
    int res = 0;
    for(int i = 0;i < 25;i++)
    {
        res += (_a[i] ? (1 << i) : 0);
    }
    return res;
}
constexpr int N = 5e5 + 5;
int n,k,ans = 0;
vector<int>a;
int dfs(int num,int bf,int idx)
{
    int res = 0;
    if(idx >= n) return num;
    if(xo(a[idx],bf) == k) res += dfs(num + 1,0,idx + 1);
    res += dfs(num,xo(a[idx],bf),idx + 1) + dfs(num,0,idx + 1);
}
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    bool way = true;
    for(int i = 1;i <= n;i++)
    {
        int k;cin >> k;
        if(k > 1) way = false;
        a.push_back(k);
    }
    if(way)
    {
        if(k == 0)
        {
            a.push_back(-114514);
            for(int i = 0;i < n;i++)
            {
                if(a[i] == 0) ans++;
                else if(a[i] == a[i + 1] && a[i] == 1)
                {
                    ans++,i++;
                }
            }
        }
        else
        {
            a.push_back(a[n - 1]);
            for(int i = 0;i < n;i++)
            {
                if(a[i] == 1) ans++;
                else if(a[i] != a[i + 1]) ans++,i++;
            }
        }
    }
    else
    {
        ans = dfs(0,0,0);
    }
    cout << ans << '\n';
    return 0;
}