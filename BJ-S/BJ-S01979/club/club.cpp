#include <bits/stdc++.h>
using namespace std;

long long a[100005][5];
struct T{
    long long d,maxx,midd;
    long long maxid,midid;
}b[100005];

bool cmp(T x,T y)
{
    return x.d > y.d;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        for(int i = 1;i <= n;i++)
        {
            long long maxn = -1,minn= 1e9,sum = 0;
            long long maxi,mini,midi;
            for(int j = 1;j<=  3;j++)
            {
                cin >> a[i][j];
                sum += a[i][j];
                if(a[i][j] > maxn)
                {
                    maxn = a[i][j];
                    maxi = j;
                }
                if(a[i][j] <= minn)
                {
                    minn = a[i][j];
                    mini = j;
                }
            }
            long long midn = sum - maxn - minn;
            midi = 6 - maxi - mini;
            b[i].d = maxn - midn;
            b[i].maxx = maxn;
            b[i].midd = midn;
            b[i].maxid = maxi;
            b[i].midid = midi;
        }
        sort(b + 1,b + n + 1,cmp);
        long long cnt1 = 0,cnt2 = 0,cnt3 = 0;
        long long ans = 0;
        for(int i = 1;i <= n;i++)
        {
            if(b[i].maxid == 1)
            {
                if(cnt1 < n / 2)
                {
                    cnt1++;
                    ans += b[i].maxx;
                }
                else
                {
                    if(b[i].midid == 2)
                    {
                        cnt2++;
                        ans+=b[i].midd;
                    }
                    else
                    {
                        cnt3++;
                        ans+=b[i].midd;
                    }
                }
            }
            else if(b[i].maxid == 2)
            {
                if(cnt2 < n / 2)
                {
                    cnt2++;
                    ans += b[i].maxx;
                }
                else
                {
                    if(b[i].midid == 1)
                    {
                        cnt1++;
                        ans+=b[i].midd;
                    }
                    else
                    {
                        cnt3++;
                        ans+=b[i].midd;
                    }
                }
            }
            else if(b[i].maxid == 3)
            {
                if(cnt3 < n / 2)
                {
                    cnt3++;
                    ans += b[i].maxx;
                }
                else
                {
                    if(b[i].midid == 2)
                    {
                        cnt2++;
                        ans+=b[i].midd;
                    }
                    else
                    {
                        cnt1++;
                        ans+=b[i].midd;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
