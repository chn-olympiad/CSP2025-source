#include <iostream>
#include <algorithm>

using namespace std;
const int MAXN = 5e5 + 5;
int n, k, a[MAXN], v[MAXN], pos, x[MAXN], y[MAXN], ans = 1;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        v[i] = v[i - 1] ^ a[i];
    for(int i = 1; i <= n; i++)
    {
        for(int j = i; j <= n; j++)
        {
            int num = v[j] ^ v[i - 1];
            if(num == k)
                x[++pos] = i, y[pos] = j;
        }
    }
    if(pos == 0) cout << 0;
    else
    {
        int mx = x[1], my = y[1];
        for(int i = 2; i <= pos; i++)
        {
            if(my < x[i])
            {
                ans++;
                mx = x[i], my = y[i];
            }
        }
        cout << ans;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
