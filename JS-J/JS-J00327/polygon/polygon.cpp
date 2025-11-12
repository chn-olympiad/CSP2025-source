#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=3;i<=n;i++)
    {
        unsigned long long cnt=1;
        for(int j=1;j<=i;j++)
        {
            cnt=cnt*(n-j+1);
        }
        for(int j=i;j>=2;j--)
        {
            cnt=cnt/j;
        }
        ans+=cnt%998244353;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
