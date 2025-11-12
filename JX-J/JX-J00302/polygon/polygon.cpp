#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[10000],sum1=0,b=-1;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n<=2)
    {
        sum1=0;
    }
    if(n==3)
    {
        b=max(a[1],max(a[2],a[3]));
        if(2*b<a[1]+a[2]+a[3])
        {
            sum1=1;
        }
        else
        {
            sum1=0;
        }
    }
    cout << sum1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
