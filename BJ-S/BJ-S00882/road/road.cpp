#include <bits/stdc++.h>
using namespace std;
long long c,r,g,d,w,sum;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>c>>r>>g;
    for(int i=1;i<=r;i++)
    {
        cin>>d>>d>>w;
        sum+=w;
    }
    for(int i=1;i<=g;i++)
    {
        for(int j=1;j<=c+1;j++)
        {
            cin>>d;
        }
    }
    cout<<sum;
    return 0;
}
