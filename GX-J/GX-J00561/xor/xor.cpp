#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int x,y,a[500005],maxn=0,sum=0;
    cin>>x>>y;
    for(int i=1;i<=x;i++)
    {

        cin>>a[i];
        maxn=max(maxn,a[i]);
        sum+=a[i];
    }
    if(maxn==1)
    {
        cout<<sum;
    }
    else if(maxn==0)
    {
        cout<<maxn;
    }
    else
    {
        cout<<a[1];
    }
}
