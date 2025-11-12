#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,c,r,a1,a[N];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    a1=a[1];
    sort(a+1,a+n*m+1);
    int cnt=n*m;
    for(c=1;c<=m;c++)
    {
        if(c%2!=0)
            for(r=1;r<=n;r++)
            {
                if(a[cnt]==a1)
                {
                    printf("%d %d\n",c,r);
                    return 0;
                }
                cnt--;
            }

        else
            for(r=n;r>=1;r--)
            {
                if(a[cnt]==a1)
                {
                    printf("%d %d\n",c,r);
                    return 0;
                }
                cnt--;
            }
    }
    return 0;
}
