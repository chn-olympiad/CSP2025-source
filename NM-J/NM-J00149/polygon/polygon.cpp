#include <bits/stdc++.h>
using namespace std;
int n,a[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int sum=0,cnt=1;
    for(int i=3;i<=n;i++)
    {
        cnt=cnt*i%998244353;
        sum+=cnt/i;
    }
    cout<<sum;
    return 0;
}
