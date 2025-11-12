#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n * m;i++)
    {
        scanf("%d",&a[i]);
    }
    c = a[1];
    sort(a + 1,a + n * m + 1);
    for(int i = 1;i <= n * m;i++)
    {
        if(c == a[i])
        {
            i = n * m + 1 - i;
            c = (i - 1) / n + 1;
            r = (i - 1) % (n * 2) + 1;
            if(r > n)
            {
                r = 2 * n + 1 - r;
            }
            printf("%d %d",c,r);
            return 0;
        }
    }
    return 0;
}
