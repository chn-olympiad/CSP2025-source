#include <bits/stdc++.h>
using namespace std;

int n, k;
const int MAXN = 5e5+5;
int a[MAXN];
int pre[MAXN];
bool allone = true;
int ans = 0;
bool chosen[MAXN];

int fastxor(int l, int r)
{
    return pre[r] ^ pre[l - 1];
}
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != 1) allone = false;
        pre[i] = pre[i - 1] ^ a[i]; // previous xor
    }
    // special condition
    if (allone)
    {
        if (n % 2 == 0)
            cout << 0 << endl;
        else if (n % 2 == 1)
            cout << 1 << endl;
    }
    else
    {
        // normal
        //cout << fastxor(1, 2) << endl;
        // blatant
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                int res = fastxor(i, j);
                if (res == k)
                {
                    // filter index
                    bool isans = true;
                    for (int x = i; x <= j; x++)
                    {
                        if (chosen[x])
                        {
                            isans = false;
                        }
                    }
                    if (isans)
                    {
                        for (int x = i; x <= j; x++) chosen[x] = true;
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}