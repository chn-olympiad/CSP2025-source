#include <bits/stdc++.h>
using namespace std;
int n,a[5010],ans,cnt=3;
int main()
{
    freopen("polygon.in","w",stdin);
    freopen("polygon.out","r",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    while(cnt<=n)
    {
        for(int i=cnt;i<=n;i++)
        {
            int sum=2*max(a[i],max(a[i-1],a[i-2]));
            if(a[i]+a[i-1]+a[i-2]>sum)
            {
                ans++;
            }
        }
        cnt++;
    }
    cout<<ans;
    return 0;
}
