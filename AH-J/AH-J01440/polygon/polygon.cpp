#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e6+5;
const int mod = 998244353;

int n,m;
int a[maxn];
int b[maxn];
int sum ;
int ans = 0;
void dfs(int dep)
{
    if(dep > n)
    {
        int maxtick = -1;
        int cnt = 0;
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(b[i])
            {
                cnt++;
                sum += a[i];
                maxtick = std::max(a[i],maxtick);
            }
        }
        if(cnt <= 2)return;
        if(sum > 2 * maxtick){
            ans += 1;
            ans %= mod;
        }
        // cout << endl;
        return;
    }
    for(int i = 0;i <= 1;i++)
    {
        b[dep] = i;
        dfs(dep + 1);
    }
}

void init()
{
    cin >> n;
    int maxbon = -1;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum += a[i];
        maxbon = max(maxbon,a[i]);
    }
    if(n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    if(n == 3)
    {
        bool flag = 1;
        if(sum <= 2 * maxbon)
        {
            cout << 0 << endl;
            return;
        }
        cout << 1 << endl;
        return;
    }
    dfs(1);
    cout << ans << endl;
}

void work()
{

}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    work();
    return 0;
}