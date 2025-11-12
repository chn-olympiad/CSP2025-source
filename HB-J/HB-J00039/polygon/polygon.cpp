#include <bits/stdc++.h>
using namespace std;
int n,ans;
int a[5005];
int main()
{
    freopen(polygon.in,"r",stdin);
    freopen(polygon.out,"w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    if(n==3)
    {
        int sumn;
        for(int i=1;i<=n;i++)
            sumn+=a[i];
        if(sumn>2*max(a[1],max(a[2],a[3])))
        {
            ans=1;
        }
    }
    cout << ans;
    return 0;
}
