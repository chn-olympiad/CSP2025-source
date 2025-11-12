#include <iostream>
#include <algorithm>
#define P 998244353
using namespace std;

int n, m, ans, c[505], s[505], p[505];
int main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        scanf("%1d", s + i);
    for(int i = 1; i <= n; i++)
        cin >> c[i], p[i] = i;
    do
    {
        int cnt = 0, sum = 0;
        for(int i = 1; i <= n; i++)
            if(s[i])
                if(c[p[i]] > sum)
                    cnt++;
                else
                    sum++;
            else
                sum++;
        ans += (cnt >= m);
    }while(next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}
