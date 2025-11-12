#include <bits/stdc++.h>
using namespace std;

long long re[5000] = {0, 0, 0, 6}, a[5005], usecur = 0;
string used[5005];

int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 4; i <= n; i++) re[i] = i * re[i - 1];
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 3; i <= n; i++)
    {
        long long maxn = -1, cnt = 0;
        do
        {
            long long tmp[5005], cur = 0, sum = 0;
            bool flag = true, f = true;
            memset(tmp, 0, sizeof(tmp));
            string s = "";
            for (int j = 1; j <= i; j++)
            {
                tmp[++cur] = a[j];
                sum += a[j];
                maxn = max(maxn, a[j]);
            }

            sort(tmp + 1, tmp + cur + 1);

            for (int i = 1; i <= cur; i++)
                s = s + char(tmp[i] + '0');

            for (int i = 1; i <= usecur; i++)
                if (std::equal(used[i].begin(), used[i].end(), s.begin(), s.end()))
                    flag = false;

            if (sum > maxn * 2 && flag)
            {
                cnt++;
                used[++usecur] = s;
                //cout << "#" << sum << " " << maxn << endl;
                //for (int i = 1; i <= usecur; i++) cout << "*" << used[i] << " ";
                //cout << endl;
            }

        } while (next_permutation(a + 1, a + n + 1));
        //cout << "**" << i << "---" << cnt << endl;
        ans = (ans + cnt) % 998244353;
    }
    printf("%lld", ans % 998244353 + 1);
    return 0;
}
