#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 2e6;
int n, k, a[N], l, st[M], pre[N], ans;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    for(int i = 1;i <= 2e6 - 10;i++)
    {
        st[i] = -1;
    }
	cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] ^ a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        if(st[pre[i] ^ k] >= l)
        {
            l = i;
            ans++;
        }
        st[pre[i]] = i;
    }
    cout << ans << "\n";
	return 0;
}