#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int a[10005],n=0,k=0,e=0,ans=0;
    cin>>n>>k;
    for (int i=1;i<n;i++)
    {
        cin>>a[i];
    }
    int d=0;
    for (int i=1;i<=n;i+=d)
    {
        int c=a[i];
        for (int j=i+1;j<=n;j++)
        {
            if (c==k)
            {
                d=j;
                ++ans;
                break;
            }
            c=(c^a[j]);
        }
    }
    cout<<ans;
    return 0;
}
