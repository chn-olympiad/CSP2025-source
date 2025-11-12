#include <bits/stdc++.h>

//RP++
//may be it can get 20 points

using namespace std;

const int MAXN = 5e3 + 5;

int n;
int a[MAXN];
//int book[MAXN];

int ans;

void dfs(int x, int sum, int last, int maxn)
{
    if(x == n + 1) return;

    if(sum > (2 * maxn))
    {
        // for(int i = 1; i <= n; i++)
        // {
        //     cout << book[i] << " ";
        // }
        // cout << "\n";
        ans++;
        ans%=998244353;
    }

    for(int i = last + 1; i <= n; i++)
    {
        //book[i] = 1;
        dfs(x + 1, sum + a[i], i, max(maxn, a[i]));
        //book[i] = 0;
    }

}

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);


    cin >> n;

    int maxa = 0;
    int suma = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] > maxa) maxa = a[i];
        suma += a[i];
    }

    dfs(1, 0, 0, 0);
    if(suma > (2*maxa)) ans++;
    ans%=998244353;
    cout << ans;

    return 0;
}