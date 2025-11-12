#include <iostream>
#include <cstdio>

using namespace std;

const int N = 505, MOD = 998244353;
int n, m, a[N], b[N], ans;
bool cnt[N];
string s;

void calc()
{
    int res = 0, lose = 0;
    for(int i = 1;i <= n;i++)
    {
        if(s[i-1] == '0')   lose++;
        else
        {
            if(a[b[i]] > lose)
                res++;
            else
                lose++;
        }
    }
    if(res >= m)
        ans++;
}

void dfs(int x)
{
    if(x > n)
    {
        calc();
        return ;
    }
    for(int i = 1;i <= n;i++)
    {
        if(cnt[i])  continue;
        cnt[i] = true, b[x] = i;
        dfs(x+1);
        cnt[i] = false;
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    scanf("%d %d", &n, &m);
    cin >> s;
    for(int i = 1;i <= n;i++)   scanf("%d", &a[i]);
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
