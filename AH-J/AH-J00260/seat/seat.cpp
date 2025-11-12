#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N = 100 + 5;
LL n, m, p, w = 1;
struct Q
{
    LL score, x, y;
}a[N];
bool cmp(const Q &x, const Q &y)
{
    return x.score > y.score;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(LL i=1; i<=n*m; i++)
    {
        cin >> a[i].score;
    }
    p = a[1].score;
    sort(a+1, a+n*m+1, cmp);
    a[1].x = 1, a[1].y = 1;
    if(a[1].score == p)
    {
        printf("1 1");
        return 0;
    }
    if(n == 1)
    {
        for(LL i=1; i<=n*m; i++)
        {
            if(a[i].score == p)
            {
                printf("%lld 1", i);
            }
        }
        return 0;
    }
    if(m == 1)
    {
        for(LL i=1; i<=n*m; i++)
        {
            if(a[i].score == p)
            {
                printf("1 %lld", i);
            }
        }
        return 0;
    }
    for(LL i=2; i<=n*m; i++)
    {
        if(a[i-1].x == n && i != n*m && w == 1)
        {
            a[i].x = a[i-1].x;
            a[i].y = a[i-1].y + 1;
            w = -1;
        }
        else if(a[i-1].x == 1 && i != n*m && i > n)
        {
            a[i].x = a[i-1].x;
            a[i].y = a[i-1].y + 1;
            w = 1;
        }
        else
        {
            a[i].x = a[i-1].x + w;
            a[i].y = a[i-1].y;
        }
        if(a[i].score == p)
        {
            printf("%lld %lld", a[i].y, a[i].x);
            break;
        }
    }
    return 0;
}
