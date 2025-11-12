#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
struct node
{
    int best,b2,b3;
    int id1,id2,id3;
}a[N];
bool cmp(node x,node y)
{
    if(x.id1 == y.id1) return x.best > y.best;
    return x.id1 < y.id1;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,x,y,z,mid;
    cin >> T;
    while(T --)
    {
        for(int i = 1;i <= n;i ++)
        {
            a[i].id1 = 0;
            a[i].id2 = 0;
            a[i].id3 = 0;
            a[i].best = 0;
            a[i].b2 = 0;
            a[i].b3 = 0;
        }
        cin >> n;
        for(int i = 1;i <= n;i ++)
        {
            cin >> x >> y >> z;
            if(x >= y && y >= z) a[i].id1 = 1,a[i].id2 = 2,a[i].id3 = 3,a[i].best = x,a[i].b2 = y,a[i].b3 = z;
            else if(y >= x && x >= z) a[i].id1 = 2,a[i].id2 = 1,a[i].id3 = 3,a[i].best = y,a[i].b2 = x,a[i].b3 = z;
            else if(x >= z && z >= y) a[i].id1 = 1,a[i].id2 = 3,a[i].id3 = 2,a[i].best = x,a[i].b2 = z,a[i].b3 = y;
            else if(y >= z && z >= x) a[i].id1 = 3,a[i].id2 = 1,a[i].id3 = 2,a[i].best = z,a[i].b2 = x,a[i].b3 = y;
            else if(z >= y && y >= x) a[i].id1 = 3,a[i].id2 = 2,a[i].id3 = 1,a[i].best = z,a[i].b2 = y,a[i].b3 = x;
            else if(z >= x && x >= y) a[i].id1 = 2,a[i].id2 = 3,a[i].id3 = 1,a[i].best = z,a[i].b2 = x,a[i].b3 = y;
        }
        sort(a + 1,a + n + 1,cmp);
        int mid = n / 2;
        int ans1 = 0,ans2 = 0,ans3 = 0;
        for(int i = 1;i <= n;i ++)
        {
            if(a[i].id1 == 1) ans1 ++;
            if(a[i].id1 == 2) ans2 ++;
            if(a[i].id1 == 3) ans3 ++;
        }
        if(ans1 <= mid && ans2 <= mid && ans3 <= mid)
        {
            long long ans = 0;
            for(int i = 1;i <= n;i ++)
            {
                ans += a[i].best;
            }
            cout << ans << endl;
        }
        else
        {
            long long ans = 0;
            int cnt1 = 0;
            if(ans1 > mid)
            {
                for(int i = 1;i <= ans1 - 1;i ++)
                {
                    if(a[i].best + a[mid + i].b2 > a[i].b2 + a[mid+ i].best && cnt1 < mid) cnt1 ++,ans += a[i].best + a[mid + i].b2;
                    else ans += a[i].b2 + a[mid + i].best;
                }
                for(int i = ans1 + 1;i <= n;i ++) ans += a[i].best;
            }
            else
            {
                if(ans2 > mid)
                {
                    for(int i = 1;i <= ans2 - 1;i ++)
                    {
                        if(a[i].best + a[mid + i].b2 > a[i].b2 + a[mid + i].best && cnt1 < mid) cnt1 ++,ans += a[i].best + a[mid + i].b2;
                        else ans += a[i].b2 + a[mid + i].best;
                    }
                    for(int i = ans2 + 1;i <= n;i ++) ans += a[i].best;
                }
                else
                {
                    if(ans3 > mid)
                    {
                        for(int i = 1;i <= ans3 - 1;i ++)
                        {
                            if(a[i].best + a[mid + i].b2 > a[i].b2 + a[mid + i].best && cnt1 < mid) cnt1 ++,ans += a[i].best + a[mid + i].b2;
                            else ans += a[i].b2 + a[mid + i].best;
                        }
                        for(int i = ans3 + 1;i <= n;i ++) ans += a[i].best;
                    }
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}
