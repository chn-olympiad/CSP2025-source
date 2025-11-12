#include <bits/stdc++.h>
using namespace std;
#define int long long
#define get(i) ((a[i][0] > a[i][1]) ? ((a[i][0] > a[i][2]) ? 0 : 2) : ((a[i][1] > a[i][2]) ? 1 : 2))
const int _ = 1e5 + 5;

int rd()
{
    int x = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return x * f;
}

int t, n;
int ans, res, mx;
int a[_][3], cnt[3], srt[_];

signed main()
{
     freopen("club.in", "r", stdin);
     freopen("club.out", "w", stdout);
    t = rd();
    while(t--)
    {
        ans = 0, res = 0;
        memset(cnt, 0, sizeof(cnt));
        n = rd();
        for(int i = 1; i <= n; i++) 
        {
            for(int j = 0; j < 3; j++) a[i][j] = rd();
            cnt[get(i)]++;
        }
        mx = ((cnt[0] > n / 2) ? 0 : ((cnt[1] > n / 2) ? 1 : 2));
        for(int i = 1; i <= n; i++)
        {
            ans += a[i][get(i)];
            if(get(i) == mx)
                srt[++res] = a[i][mx] - max({(mx == 0 ? 0 : a[i][0]), (mx == 1 ? 0 : a[i][1]), (mx == 2 ? 0 : a[i][2])});
        }
        sort(srt + 1, srt + res + 1);
        for(int i = 1; i <= res - n / 2; i++)
            ans -= srt[i];
        cout << ans << "\n";
    }
    return 0;
}
/*
input:
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

output:
18
4
13

*/
