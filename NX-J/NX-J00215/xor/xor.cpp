#include<bits/stdc++.h>
using namespace std;
int num[500500][500500];
struct tff
{
    int pt, dt;
}a[500500];
int Xorr(int x, int y)
{
    return abs((x | y) - (x & y));
}
bool cmp(tff x, tff y)
{
    return x.dt < y.dt;
}
int main()
{
    freopen("xor.in","r", stdin);
    freopen("xor.out", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", num[i][i]);
        if(num[i][i] == k)
        {
            a[cnt].pt = i;
            a[cnt].dt = i;
            cnt++;
        }
    }
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= n - i + 1; j++)
        {
            num[j][j + i -1] = Xorr(num[j][j + i - 2], num[j + i - 1][j + i - 1]);
            if(num[j][j + i - 1] == k)
            {
                a[cnt].pt = j;
                a[cnt].dt = j+i -1;
                cnt++;
            }
        }
    }
    sort(a, a+cnt, cmp);
    int ans = 0;
    int fd = 0;
    for(int i = 0; i < cnt; i++)
    {
        if(a[i].pt > fd)
        {
            ans++;
            fd = a[i].dt;
        }
    }
    printf("%d", ans);
    return 0;
}
