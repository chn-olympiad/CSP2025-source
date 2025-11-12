#include <bits/stdc++.h>
using namespace std;

int r[20] , c[20] , vis[20];
char s[20];
int n , m , cnt;
void dfs(int x)
{
    if(x > n)
    {
        int cantgo = 0;
        for(int i = 1; i <= n; i++)
        {
            if(cantgo >= c[r[i]] || s[i] == '0') cantgo++;
        }
        if((n - cantgo) >= m) cnt++;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            r[x] = i;
            vis[i] = 1;
            dfs(x + 1);
            r[x] = 0;
            vis[i] = 0;
        }
    }
}
int main()
{
    freopen("employ.in" , "r" , stdin);
    freopen("employ.out" , "w" , stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> s[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    dfs(1);
    cout << cnt << endl;
    return 0;
}
