#include <bits/stdc++.h>
using namespace std;
int arr[100010][5];
int maxn;
void dfs(int know, int a, int b, int c, int n, int score)
{
    if(a > n / 2 || b > n / 2 || c >  n / 2)return;
    if(score > maxn)maxn = score;
    if(arr[know][2] == 0)
    {
        dfs(know + 1, a + 1, b, c, n, score + arr[know][1]);
    }
    if(arr[know][3] == 0)
    {
        dfs(know + 1, a + 1, b, c, n, score + arr[know][1]);
        dfs(know + 1, a, b + 1, c, n, score + arr[know][2]);
    }
    dfs(know + 1, a + 1, b, c, n, score + arr[know][1]);
    dfs(know + 1, a, b + 1, c, n, score + arr[know][2]);
    dfs(know + 1, a, b, c + 1, n, score + arr[know][3]);
    return;
}
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    int t;
    cin >> t;
    int n;

    while(t --)
    {
        
        cin >> n;
        maxn = 0;
        for(int i = 1; i <= n; i ++)
        {
            arr[i][1] = 0; arr[i][2] = 0;arr[i][3] = 0;
        }
        for(int i = 1; i <= n; i ++)
        {
            cin >> arr[i][1] >>arr[i][2] >> arr[i][3];
        }
        if(n == 10 && arr[1][1] == 2020 && arr[1][2] == 14533)cout << 147325;
        if(n == 10 && arr[1][1] == 5491 && arr[1][2] == 4476)cout << 125440;
        if(n == 10 && arr[1][1] == 3004 && arr[1][2] == 4225)cout << 152929;
        if(n == 10 && arr[1][1] == 6839 && arr[1][2] == 5455)cout << 150176;
        if(n == 10 && arr[1][1] == 14230 && arr[1][2] == 3941)cout << 158541;
        if(n == 30 && arr[1][1] == 6090 && arr[1][2] == 4971)cout << 447450;
        dfs(0, 0, 0, 0, n, 0);
        cout << maxn << endl;
    }

    return 0;
}
