#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5e3 + 10;
using lint = long long;
int n;
lint st[N],mul[N];
lint qpow(lint a,int b)
{
    ans = 1;
    while(b)
    {
        if(b & 1)
        {
            ans *= ans * a;
            ans %= mod;
        }
        else
        {
            ans *= ans;
            ans %= mod;
        }
        b <<= 1;
    }
    return ans;
}
lint dfs(int stick,int sum,int maxn,int posPre)
{
    if(stick == 0)
    {
        if(sum > maxn * 2)
        {
            return 1;
        }
        return 0;
    }
    lint ans = 0;
    for(int i = 1;i < posPre;i++)
    {
        ans += dfs(stick - 1,sum + st[i],maxn,i);
        ans %= mod;
    }
    return ans;
}
int main()
{
    freopen("polygon.in","r",stdin);
//    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    lint cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> st[i];
        if(st[i] == 1)
        {
            cnt++;
        }
    }
    if(cnt == n)
    {
        for(int i = 1;i <= n;i++;)
        {
            mul[i] = i * mul[i - 1];
            mul[i] %= mod;
        }
        lint ans = 0;
        for(int i = 3;i <= n;i++)
        {
            ans += mul[i] * mul[n - i] * qpow(mul[n]);
        }
        cout << ans;
    }
    else
    {
        sort(st + 1,st + 1 + n);
        lint ans = 0;
        for(int i = 3;i <= n;i++)
        {
            for(int j = n;j >= i;j--)
            {
                ans += dfs(i,st[j],st[j],j);
                ans %= mod;
            }
        }
        cout << ans;
    }
	return 0;
}
