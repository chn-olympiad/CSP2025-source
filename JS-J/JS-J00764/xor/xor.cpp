#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[500010];
int prexor[500010];
int x[500010];
int maxn(int n1, int n2, int n3)
{
    //cout << n1 << ' ' << n2 << ' ' << n3 << endl;
    return max(n1, max(n2, n3));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        prexor[i] = prexor[i - 1] ^ a[i];
        x[i] = (a[i] == k);
    }
    /*
    for(int i = 1; i <= n; i++)
        cout << prexor[i] << ' ';
    cout << '\n';
    */
    for(int i = 1; i < n; i++)
    {
        /*
        for(int j = 1; j <= n - i + 1; j++)
        {
            cout << x[j] << ' ';
        }
        cout << '\n';
        */
        for(int j = 1; j <= n - i; j++)
        {
            x[j] = maxn(x[j] + (a[i + j] == k), x[j + 1] + (a[j] == k), (prexor[i + j] ^ prexor[j - 1]) == k);
        }
    }
    cout << x[1];
    return 0;
}
