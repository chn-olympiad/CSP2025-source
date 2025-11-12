#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int cnt=0;
    if (a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[2]+a[3]>a[1]) cnt++;
    printf("%d",cnt%998244353);
    return 0;
}
