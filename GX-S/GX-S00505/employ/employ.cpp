#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int N = 500 + 10;
const long long mod = 998244353;

long long n,m,ans = 0;
int pat[N] = { 0 },a[N] = { 0 },s[N] = { 0 };
bool vis[N] = { false };
string line;

long long work(long long x)
{
	if (x == 0) return 1;
    long long sum = 1;
    while (x > 0)
    {
        sum *= x;
        sum %= mod;
        --x;
    }
    return sum;
}

bool check()
{
    int h = 0, last = 0;
    for (int i = 0; i < n; i++)
    {
        if (line[i] == '0') ++last;
        if (line[i] == '1' && a[i + 1] < last) ++h;
    }
    return h >= m;
}

void DFS(int depth = 1)
{
    if (depth == n + 1)
    {
        if (check()) ++ans;
        ans %= mod;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        a[depth] = pat[i];
        vis[i] = true;
        DFS(depth + 1);
        vis[i] = false;
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios :: sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    cin >> line;
    for (int i = 1;i <= n; i++) s[i] = s[i - 1] + (line[i - 1] == '0');
    for (int i = 1; i <= n; i++) cin >> pat[i];
    DFS();
    if (n > 10)
    {
        if (n - s[n] > m) ans = 0;
        else
        {
            ans = 1;
            sort(pat + 1, pat + 1 + n);
            int ss = 1;
            while (ss < n)
            {
                int len = 1;
                for (int i = ss; i < n; i++)
                {
					++ss;
                    if(pat[i] == pat[i + 1]) ++len;
                    else break; 
                }
                long long xx = ss;
                xx = ss == n ? ss : ss - 1;
                long long mm = len - (s[len + ss - 1] - s[xx]);
                if (mm == 0) len = 0;
                long long f = work(len) / (work(len - mm) * work(mm));
                if (mm == len) ans = (ans * work(len)) % mod;
                else ans = (ans * f) % mod;
            }
        }
    } 
    cout << ans << '\n';
    return 0;
}
