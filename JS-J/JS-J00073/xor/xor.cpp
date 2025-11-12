#include <bits/stdc++.h>
#define int long long
const int MAXN = 5e5 + 6;
using namespace std;
int n, k;
int a[MAXN], pre[MAXN];
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%lld %lld",&n, &k);
    for (int i = 1; i <= n; i ++)
        scanf("%lld",&a[i]);
    for (int i = 1; i <= n; i ++)
    {
        pre[i] = pre[i-1] ^ a[i];
    }
  //  for (int i = 1; i <= n; i ++)cout << pre[i] << ' ';
   // cout << endl;
    int ans = 0;


    for (int l = 1; l <= n;)
    {
        if(a[l] == k)
        {
            ans ++;
//            cout << ans << ":" << l << endl;
            l++;
            continue;
        }
        bool flag = 1;
        for (int r = l+1; r <= n; r ++)
        {
            if((int)(pre[r] ^ pre[l-1]) == k)
            {
                flag = 0;
                ans ++;
          //      printf("%lld: [%lld,%lld]\n",ans,l,r);
                l = r + 1;
                break;
            }
        }
        if(flag == 1) l++;
    }


    printf("%lld",ans);
    return 0;
}
