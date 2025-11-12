#include<iostream>
#include<cstdio>
using namespace std;

int n, m, ans = 0;
char s[1000];
int c[505];
bool vis[505];

void dfs(int x)
{
    if(x > m) ans++;
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    scanf("%d%d", &n, &m);
    scanf("%s", s);
    for(int i = 1; i <= n; i++) scanf("%d", &c[i]);

    dfs(1);

    printf("%d", ans % 988244353);

    return 0;
}
