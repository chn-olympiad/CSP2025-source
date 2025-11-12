#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 100010;
int a[N];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long h = 0;
    int ans;
    for(int l = 1;l <= n;l++)
    {
        for(int r = l;r <= n;r++)
        {
            for(int i = l;i < r;i++)
            {
                h += a[i] | a[i + 1];
            }
            if(h == k)
            {
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
