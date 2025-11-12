#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n=0,a[6000],f[6000],ans=0;
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>a[i];

    }
    f[0]=0;
    for (int i=1;i<=m;i++)
    {
        ans=max(ans,a[i]);
        n+=a[i];
        f[i]+=f[i-1];
        if (n>=ans*2)
        {
            f[i]+=f[i-1]+1;
        }
    }
    cout<<f[m]+2;
    return 0;
}

