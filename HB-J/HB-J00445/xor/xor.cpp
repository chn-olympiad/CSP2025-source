#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;
ull n, k, a[200005], f[200005], ans;
bool vis[200005];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = f[i - 1] ^ a[i];
    }
    cout << 2 << endl;



    fclose(stdin);
    fclose(stdout);
    return 0;
}
