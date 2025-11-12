#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[5010];
const int N = 998244353;
int ans = 0;
int n;

void dfs(int i , int sum , int maxn)
{
    //cout << n << endl;
    if(i == n + 1)
    {
        if(sum > 2 * maxn) ans = (ans + 1) % N;
        return;
    }
    //cout << i << " " << sum << " " << maxn << endl;
    dfs(i + 1 , sum + a[i] , max(maxn , a[i]));
    dfs(i + 1 , sum , maxn);
}

signed main()
{
    //ctrl + s!!!!!!
    freopen("polygon.in" , "r" , stdin);
    freopen("polygon.out" , "w" , stdout);
    cin >> n;
    int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        maxn = max(maxn , a[i]);
    }
    if(maxn == 1)
    {
        int ans = 0;
        int sum = n , cnt = 1;
        int f = 0;
        //C n 1
        f = (f + (sum / cnt) % N) % N;
        sum *= n - 1;
        cnt *= 2;
        //Cn2
        f = (f + (sum / cnt) % N) % N;
        sum = (sum * (n - 2)) % N;
        cnt *= 3;
        int t;
        if(n % 2 == 0)
            t = n / 2 - 1;
        else t = (n - 1) / 2;
        for(int i = 3;i <= t;i++)
        {
            ans = (ans + (sum / cnt) % N) % N;
            sum = (sum * (n - i)) % N;
            cnt *= (i + 1);
        }
        ans *= 2;
        ans += f;
        if(n % 2 == 0) ans = (ans + (sum / cnt) % N) % N;
        cout << ans + 1 << endl;
        return 0;
    }
    dfs(1 , 0 , 0);
    cout << ans << endl;
    return 0;
}
