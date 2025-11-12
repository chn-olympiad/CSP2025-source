#include<bits/stdc++.h>
using namespace std;
int n,sum;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        sum+=x;
    }
    cout<<(sum%12+1)%998244353;
    return 0;
}
