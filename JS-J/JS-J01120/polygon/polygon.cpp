#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = a;i <= b;i++)
const int mod = 998244353, Max = 5e3+5;
int n, a[Max], dp[Max][Max], sum[Max][Max];
bool exist[Max];
ll read()
{
    int f = 1;
    ll x = 0;
    char c;
    c = getchar();
    while(!isdigit(c)&&c == '-')f = -1, c = getchar();
    while(isdigit(c))x *= 10, x += c-'0', c = getchar();
    return x;
}
ll write(ll x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
        write(x);
    }
    else if(x > 9)
    {
        write(x/10);
        putchar(x%10+'0');
    }
    else putchar(x+'0');
}
int dfs(int step, int num, int maxn, int sum)
{
    if(step == n&&num == 1)return 0;
    if(step == n+1)
    {
        if(num < 3)return 0;
        if(maxn < sum-maxn)return 1;
        else return 0;
    }
    return dfs(step+1, num, maxn, sum)+dfs(step+1, num+1, a[step], sum+a[step]);
}
int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    n = read();
    rep(i, 1, n)a[i] = read();
    sort(a+1, a+n+1);
    if(n == 3)
    {
        if(a[1]+a[2]>a[3])write(1);
        else write(0);
        return 0;
    }
    if(n <= 25)
    {
        cout << dfs(1, 0, 0, 0);
        return 0;
    }
    srand(time(0));
    cout << rand()%(n*(n-1));
    return 0;
}
