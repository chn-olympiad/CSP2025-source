#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
struct node
{
    int score, id;
}a[N][4];
int cnt[4];
int ans, n;
vector<int> ve;
void dfs(int x)
{
    if(x == n + 1)
    {
        int sum = 0;
        for(int v : ve)
            sum += v;
        ans = max(ans, sum);
        return;
    }
    for(int i = 1;i <= 3;i++)
    {
        if(cnt[i] < n / 2)
        {
            cnt[i]++;
            ve.push_back(a[x][i].score);
            dfs(x + 1);
            cnt[i]--;
            ve.pop_back();
        }
    }
}

signed main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        memset(cnt, 0, sizeof(cnt));
        ans = 0;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 1;j <= 3;j++)
            {
                a[i][j].id = j;
                cin >> a[i][j].score;
            }
        }
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}
