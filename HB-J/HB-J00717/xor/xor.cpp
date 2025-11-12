#include <bits/stdc++.h>
using namespace std;
int a[500005];
int pre[500005];
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int t = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        // int tmp;
        // cin >> tmp;
        // t ^= tmp;
        // if(tmp == k)
        // {
        //     ans++;
        // }
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int j = i - 1;
        do
        {
            j++;
            t ^= a[j];
            cnt++;
        }while(j <= n && t != k);
        if(t != k)
        {
            t = 0;
            continue;
        }
        ans++;
        t = 0;
        i = j;
    }
    cout << ans;
    return 0;
}