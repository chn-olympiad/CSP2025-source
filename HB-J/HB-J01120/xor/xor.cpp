#include <bits/stdc++.h>
using namespace std;
int n,k,cnt0,cnt1,a[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            cnt0++;
        }
        if(a[i]==1)
        {
            cnt1++;
        }
    }
    if(k==0)
    {
        ans=cnt0+cnt1/2;
    }
    else if(k==1)
    {
        ans=cnt1;
    }
    cout<<ans;
    return 0;
}
