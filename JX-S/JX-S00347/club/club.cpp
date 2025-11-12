#include<bits/stdc++.h>
using namespace std;
int t, n, a[100005], b[100005], c[100005], apos, bpos, cpos, ai[100005], bi[100005], ci[100005], z[100005];
long long ans;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while (t--)
    {
        ans = 0;
        apos = 0;
        bpos = 0;
        cpos = 0;
        memset(z, 0x3f3f3f, sizeof(z));
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i] >> b[i] >> c[i];
            ans += max(a[i], max(b[i], c[i]));
            if (a[i] >= b[i] && a[i] >= c[i]) ai[++apos] = i;
            else if (a[i] <= b[i] && b[i] >= c[i]) bi[++bpos] = i;
            else ci[++cpos] = i;
        }
        int maxpos = max(apos, max(bpos, cpos));
        if (maxpos*2 > n)
        {
            if (apos == maxpos) for (int i = 1; i <= maxpos; i++) z[i] = a[ai[i]]-max(b[ai[i]], c[ai[i]]);
            else if (bpos == maxpos) for (int i = 1; i <= maxpos; i++) z[i] = b[bi[i]]-max(a[bi[i]], c[bi[i]]);
            else for (int i = 1; i <= maxpos; i++) z[i] = c[ci[i]]-max(b[ci[i]], a[ci[i]]);
            sort (z+1, z+maxpos+1);
            int mpos = maxpos-n/2;
            for (int i = 1; i <= mpos; i++) ans -= z[i];
        }
        cout << ans << '\n';
    }
    return 0;
}
