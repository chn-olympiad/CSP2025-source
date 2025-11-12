#include<bits/stdc++.h>
using namespace std;
int a[5010];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int ans=0;
    int n;
    cin>>n;
    for (int  i=3;i<=n;i++)
    {
        int t=1;
        int ti=i;
        if (ti>n/2) ti=n-ti;
        for (int j=n;j>n-ti;j--)    t*=j;
        for (int j=1;j<=ti;j++) t/=j;
        ans+=t;
    }
    cout<<ans;
}
