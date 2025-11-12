#include <bits/stdc++.h>
using namespace std;
int n,a[100001],k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    cout<<n/2;
    return 0;
}
