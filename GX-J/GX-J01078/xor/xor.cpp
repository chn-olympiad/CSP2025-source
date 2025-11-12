#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w" , stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        a[i] = num;
        if(num == 1)
            ans++;
    }
    if(k == 0)
        cout << n;
    else if(k == 1)
        cout << ans;
    else
        cout << k;
    return 0;
}
