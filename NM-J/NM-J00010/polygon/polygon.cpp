#include <bits/stdc++.h>
using namespace std;
int a[5010];
long long ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    if(n<3)
    {
        cout<<0<<"\n";
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2)
    {
        ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
