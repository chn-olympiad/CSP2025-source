//Please give me some scores
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a[600000];

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k, res = 0, cnt = 0;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
    {
        int h = res;
        res = res ^ a[i];
        if (res < h && res < k)
        {
            continue;
        }
        if (res == k)
        {
            res = 0;
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}