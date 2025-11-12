#include<iostream>
#include<string>

using namespace std;

const int Potata = 505;

int n, m;
string str;
int val[Potata];

int ans;
int arr[Potata];
int vis[Potata];

bool check()
{
    int False = 0;
    int True = 0;

    for (int i = 0; i < n; i++)
        if (str[i] == '0' || val[arr[i + 1]] <= False)
            False++;
        else
            True++;

    return (True >= m);
}

void dfs(int cur)
{
    if (cur == n + 1)
        ans += check();

    for (int i = 1; i <= n; i++)
        if (vis[i] == false)
            arr[cur] = i,
            vis[i] = true,
            dfs(cur + 1),
            vis[i] = false,
            arr[cur] = 0;
}

int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);

    cin >> n >> m >> str;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    if (n <= 20)
        dfs(1),
        cout << ans;
    else
        cout << 0;

    return 0;
}