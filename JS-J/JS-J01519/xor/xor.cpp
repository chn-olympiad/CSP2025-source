#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, ans;
int a[N], pre[N];
bool vis[N];
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
        if(a[i] == k) vis[i] = true, ans++;
    }
    int i = 0;
    while(i <= n)
    {
        // use i as start
        int j = i + 1;
        if(vis[j])
        {
            i++;
            continue;
        }
        while(j <= n && !vis[j])
        {
            int x = pre[j] ^ pre[i];
            x ^= k;
        //    cout << i << ' ' << j << ' ' << x << '\n';
            if(x == 0)
            {
                ans++;
                i = j - 1;
                break;
            }
            bool flag = false;
            for(int p = i + 1; p < j; p++)
            {
                if((pre[p] ^ pre[i]) == x)
                {
//                    cout << pre[p] << ' ' << pre[i] << ' ' << (pre[p] ^ pre[i]) << ' ' << x << '\n';
                    flag = true;
                }
            }
            if(flag)
            {
                ans++;
 //               cout << i << ' ' << j << '\n';
                i = j - 1;
                break;
            }
            else j++;
        }
        i++;

    }
    cout << ans;
	return 0;
}
