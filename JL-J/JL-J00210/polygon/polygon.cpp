#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5500],cnt=0,s=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n-2;i++)
    {
        for(int j=1;j<=i;j++)
        {
            s=s+j;
        }
    }
    cout<<s%998244353;
    return 0;
}
