#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long

const ll N = 500005;
ll n, a[N][3], ans, tot, p[N], c[N], t;

bool cmp(ll x, ll y)
{
    return x > y;
}

struct node
{
    ll val, id, pos;
} cnt[500005];

bool cmp1(node x, node y)
{
    if(x.val != y.val)
        return x.val < y.val;
    return x.pos < y.pos;
}

void check(ll k)
{
    tot = 0;
    if(c[k] > n / 2){
        for(ll i = 1; i <= n; i ++)
            if(p[i] == k)
            {
                cnt[++ tot].id = i;
                ll p = 0, id = 0;
                for(ll l = 0; l <= 2; l ++)
                    if(k != l && a[i][l] <= a[i][k] && a[i][l] >= p)
                    {
                        p = max(a[i][l], p);
                        id = l;
                    }
                cnt[tot].val = a[i][k] - p;
                cnt[tot].pos = id;
            }
        sort(cnt + 1, cnt + tot + 1, cmp1);
        ll m = c[k];
        for(int i = 1; i <= m - n / 2; i ++)
        {
            ans -= cnt[i].val;
            p[cnt[i].id] = cnt[i].pos;
            c[k] --;
            c[cnt[i].pos] ++;
        }
    }
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    scanf("%lld", &t);
    while(t --)
    {
        scanf("%lld", &n);
        for(int i = 0; i <= max(2ll, n); i ++)
            c[i] = p[i] = 0;
        for(int i = 1; i <= n; i ++)
        {
            scanf("%lld %lld %lld", &a[i][0], &a[i][1], &a[i][2]);
            ans += max(a[i][0], max(a[i][1], a[i][2]));
            if(a[i][0] > a[i][1])
                if(a[i][0] > a[i][2])
                {
                    p[i] = 0;
                    c[0] ++;
                }
                else
                {
                    p[i] = 2;
                    c[2] ++;
                }
            else
                if(a[i][1] > a[i][2])
                {
                    p[i] = 1;
                    c[1] ++;
                }
                else
                {
                    p[i] = 2;
                    c[2] ++;
                }
        }
            check(0);
            check(1);
            check(2);
            check(0);
            check(1);
            check(2);
            printf("%lld\n", ans);
            ans = 0;
    }
}
