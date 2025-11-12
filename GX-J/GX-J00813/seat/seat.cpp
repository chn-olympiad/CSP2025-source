#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,a[5005],ans;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<=n;i++)
        for(int f=i;f<=n;f++)
            for(int k=f;k<=n;k++)
                if(a[f]>a[k])
                {
                    if(a[f]-a[k] < a[i] && a[f]+a[k] > a[i])
                        ans++;
                }
                else
                {
                    if(a[k]-a[f] < a[i] && a[k]+a[f]>a[i])
                        ans++;
                }
    cout << ans;
    return 0;
}
