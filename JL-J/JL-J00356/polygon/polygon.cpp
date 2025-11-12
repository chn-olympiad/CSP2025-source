#include<bits/stdc++.h>
#define mod 998244353

using namespace std;

int n,a[5005];

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
       scanf("%d",&a[i]);
    }
    if(n == 3)
    {
        if(a[1] + a[2] + a[3] >= max({a[1],a[2],a[3]}) * 2)
        {
            printf("1");
            return 0;
        }
    }
    printf("0");

    return 0;
}
