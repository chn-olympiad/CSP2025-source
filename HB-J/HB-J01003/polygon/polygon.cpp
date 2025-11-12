#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("polygon.in","R",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5010],maxx=-1,cnt = 0;
    cin>>n;

    if(n<3)
    {
        cout<<cnt;
        return 0;
    }

    for(int i=1;i<=n;i++) cin>>a[i];

    int l=1,r=3,all=0;
    while(n-2-l)
    {
        all=0;

        for(int i=l;i<=r;i++)
        {
            all+=a[i];
            maxx = max(maxx,a[i]);
        }
        if(all>maxx*2) cnt++;
        if(r==n)
        {
            l++;
            r = l+2;
        }
        else r++;
    }
    printf("%d",cnt);
    return 0;
}
