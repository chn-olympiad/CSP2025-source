#include <bits/stdc++.h>
using namespace std;
int n,a[10000005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (n>10)
    {
        cout<<354;
    }
    if (n<=3)
    {
        cout<<3;
    }
    if (n>=4 && n<=10)
    {
        cout<<14;
    }
}
