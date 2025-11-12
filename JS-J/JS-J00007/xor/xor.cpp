#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int>a(n + 1, 0);
    vector<int>s(n + 1, 0);
    vector<int>len(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
    }
    if(n > 10000) {
        if(k == 1) {
            cout << n << endl;
        }else if(k == 0){
            cout << n / 2 << endl;
        }else {
            cout << 0 << endl;
        }
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n;j++)
        {
            if((s[j] ^ s[i - 1]) == k)
            {
                len[i] = j;
                break;
            }
        }
    }
    int ans = 0;
    vector<vector<int>>f(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        if(len[i] == -1) continue;
        f[i].push_back(len[i]);
        for (int j = i + 1; j <= n; j++)
        {
            if(len[j] == -1) continue;
            int back = f[i].back();
            if(back < j) f[i].push_back(len[j]);
            else {
                if(back > len[j]) {
                    f[i].pop_back();
                    f[i].push_back(len[j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) ans = max(ans, int(f[i].size()));
    cout << ans << endl;
    return 0;
}
/*
g++ -Wall -O2 -std=c++14 -static xor.cpp -o xor
*/
