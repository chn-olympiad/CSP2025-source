#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int a[6000];
int n;
int ans=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=0;i<(1<<n);i++)
    {
        int sum=0,mx=0,num=0;
        for (int j=0;j<n;j++)
        {
            if ((i>>j)&1) sum+=a[j+1],mx=max(mx,a[j+1]),num++;
        }
        if (num>=3)
        {
            if (sum>2*mx) ans=(ans+1)%M;

        }
    }
    cout<<ans;
    return 0;
}
