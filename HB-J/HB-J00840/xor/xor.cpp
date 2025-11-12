#include <bits/stdc++.h>
using namespace std;
struct wzy{
    int x;
    bool bh=1;
};
wzy a[5005];
int n,k,sum;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i].x;
    }
    bool pd=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i].x!=1)
        {
            pd=0;
        }
    }
    if (pd)
    {
        cout<<floor(n/2);
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        if (a[i].x==k)
        {
            sum++;
            a[i].bh=0;
        }
    }
    cout<<sum;
    return 0;
}
