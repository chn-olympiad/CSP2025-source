#include<bits/stdc++.h>
using namespace std;
long long a[502];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    for(int i=1;i<502;i++)
    {
        a[i]=a[i-1]*i;
        a[i]%=998244353;
    }
    int n;
    printf("%d",a[n]);
}
