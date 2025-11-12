#include<cmath>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

int n,k;
int f[N];
int c[N];
int a[N];
int vis[N];

bool check()
{
    int sum = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int x = f[i];
        if(a[i] == 0) sum++;
        else if(sum < c[x]) cnt++;
        else sum++;
    }
    return cnt >= k;
}

int ans;
void dfs(int x)
{
    if(x > n)
    {
        if(check()) ans++;
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            f[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        a[i] = c - '0';
        if(a[i] == 1) cnt++;
    }
    int cnt2 = 0;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    dfs(1);
    cout << ans;
    return 0;
}
