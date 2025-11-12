#include <bits/stdc++.h>
using namespace std;
int n,k,s,pre[500005],p,ans;
bool cnt[1100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> s,pre[i] = pre[i - 1] ^ s;
    for (int i = 1; i <= n; i++)
    {
        cnt[pre[p]] = 1;
        while(i <= n && !cnt[pre[i] ^ k])
            cnt[pre[i++]] = 1;
        if (i <= n)
        {
            ans++;
            for (int j = p; j <= i; j++)
                cnt[pre[j]] = 0;
            p = i;
        }
    }
    cout << ans;
    return 0;
}
