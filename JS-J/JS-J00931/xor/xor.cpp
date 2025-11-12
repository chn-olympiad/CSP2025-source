#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long a[N] , n , k;
struct node
{
    int l , r;
};
node x[N];
bool cmp(node x , node y)
{
    return x.r < y.r;
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    if (n <= 5 * 1e3)
    {
        int tot = 1;
        for (int l = 1;l <= n;l++)
        {
            for (int r = l;r <= n;r++)
            {
                if ((a[r] ^ a[l-1]) == k)
                {
                    node cmp;
                    cmp.l = l , cmp.r = r;
                    x[tot++] = cmp;
                    break;
                }
            }
        }
        tot--;
        sort(x+1,x+tot+1,cmp);
        int r = 0 , ans = 0;
        for (int i = 1;i <= tot;i++)
        {
            if (x[i].l > r)
            {
                ans++;
                r = x[i].r;
            }
        }
        cout << ans;
    }
    else
    {
        int tot = 1;
        for (int l = 1;l <= n;l++)
        {
            for (int r = l;r <= n;r++)
            {
                if ((a[r] ^ a[l-1]) == k)
                {
                    node cmp;
                    cmp.l = l , cmp.r = r;
                    l = r;
                    x[tot++] = cmp;
                    break;
                }
            }
        }
        tot--;
        sort(x+1,x+tot+1,cmp);
        int r = 0 , ans = 0;
        for (int i = 1;i <= tot;i++)
        {
            if (x[i].l > r)
            {
                ans++;
                r = x[i].r;
            }
        }
        cout << ans;
    }
    return 0;
}
