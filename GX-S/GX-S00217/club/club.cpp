#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll SUP = (ll)1<<62;
const int MAXN = 100010;
const int MAXN2 = 40;
const int MAXN1 = 210;
int T,n;

struct obj
{
    int val1,val2,val3;
}a[MAXN];

int dp[MAXN2][MAXN2][MAXN2][MAXN2];
bool v[MAXN2][MAXN2][MAXN2][MAXN2];

int getdp(int x,int y,int z,int w)
{
    if (v[x][y][z][w]) return dp[x][y][z][w];
    v[x][y][z][w] = 1;

    if (x + y + z != w) return dp[x][y][z][w] = 0;
    if (x > (n>>1) || y > (n>>1) || z > (n>>1)) return dp[x][y][z][w] = 0;

    if (w == 1)
    {
        if (x == 1) return dp[x][y][z][w] = a[w].val1;
        if (y == 1) return dp[x][y][z][w] = a[w].val2;
        if (z == 1) return dp[x][y][z][w] = a[w].val3;
    }

    if (x != 0) dp[x][y][z][w] = max(dp[x][y][z][w],a[w].val1 + getdp(x-1,y,z,w-1));
    if (y != 0) dp[x][y][z][w] = max(dp[x][y][z][w],a[w].val2 + getdp(x,y-1,z,w-1));
    if (z != 0) dp[x][y][z][w] = max(dp[x][y][z][w],a[w].val3 + getdp(x,y,z-1,w-1));
    //cout << x << " " << y << " " << z << " " << w << " " << dp[x][y][z][w] << endl;
    return dp[x][y][z][w];
}

void init()
{
    for (int x=0;x<=(n>>1);x++)
    {
        for (int y=0;y<=(n>>1);y++)
        {
            for (int z=0;z<=(n>>1);z++)
            {
                for (int w=0;w<=n;w++)
                {
                    v[x][y][z][w] = dp[x][y][z][w] = 0;
                }
            }
        }
    }
}

void solve1()
{
    init();
    int ans = 0;
    for (int i=0;i<=(n>>1);i++)
    {
        for (int j=0;j<=(n>>1);j++)
        {
            if (i + j > n) continue;
            if (n-i-j > (n>>1)) continue;
            ans = max(ans,getdp(i,j,n-i-j,n));
        }
    }
    cout << ans << endl;
}

int cnt1,cnt2,cnt3,ans,sum;

bool cmp1(obj x,obj y)
{
    return max(x.val2,x.val3) > max(y.val2,y.val3);
}

bool cmp2(obj x,obj y)
{
    return x.val2 > y.val2;
}

bool cmp3(obj x,obj y)
{
    return x.val3 > y.val3;
}

void solve2()
{
    sum = ans = 0;
    cnt1 = n,cnt2 = cnt3 = 0;
    for (int i=1;i<=n;i++)
    {
        sum += a[i].val1;
        a[i].val2 -= a[i].val1;
        a[i].val3 -= a[i].val1;
    }
    sort(a+1,a+n+1,cmp1);
    int ind = 1;
    //for (int i=1;i<=n;i++) cout << i << " " << a[i].val1 << " " << a[i].val2 << " " << a[i].val3 << endl;

    //cout << ind << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
    while (cnt1 > (n>>1))
    {
        sum += max(a[ind].val2,a[ind].val3);
        if (a[ind].val2 >= a[ind].val3) cnt2 ++;
        else cnt3 ++;
        cnt1 --;
        //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
        ind ++;
    }
    //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;


    int choice = 0;
    while (ind <= n && max(a[ind].val2,a[ind].val3) > 0)
    {
        if (a[ind].val2 > a[ind].val3)
        {
            if (cnt2 == (n>>1))
            {
                sort(a+ind,a+n+1,cmp3);
                choice = 3;
                break;
            }
            cnt2 ++;
        }
        if (a[ind].val2 < a[ind].val3)
        {
            if (cnt3 == (n>>1))
            {
                sort(a+ind,a+n+1,cmp2);
                choice = 2;
                break;
            }
            cnt3 ++;
        }
        if (a[ind].val2 == a[ind].val3)
        {
            if (cnt2 < (n>>1)) cnt2 ++;
            else cnt3 ++;
        }
        sum += max(a[ind].val2,a[ind].val3);
        cnt1 --;
        //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
        ind ++;
    }

    while (ind <= n && choice == 2 && a[ind].val2 > 0)
    {
        cnt1 --;
        sum += a[ind].val2;
        cnt2 ++;
        //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
        ind ++;
    }
    //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;

    while (ind <= n && choice == 3 && a[ind].val3 > 0)
    {
        cnt1 --;
        sum += a[ind].val3;
        cnt3 ++;
        //cout << ind << " " << a[ind].val1 << " " << a[ind].val2 << " " << a[ind].val3 << " " << cnt1 << " " << cnt2 << " " << cnt3 << endl;
        ind ++;
    }

    cout << sum << endl;
}

void solve()
{
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].val1 >> a[i].val2 >> a[i].val3;
    }
    if (n <= 30) solve1();
    else solve2();
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> T;
    while (T--) solve();

    return 0;
}
