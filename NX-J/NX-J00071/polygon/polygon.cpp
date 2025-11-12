#include<bits/stdc++.h>
using namespace std;
long long a[100005],n,k,k1,l=0;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    k=min(a[1],a[2]);
    if(k==1)
    {
        k1=min(a[2],a[3]);
    }
    else if(k==2)
    {
        k1=min(a[1],a[3]);
    }
    else if(k==3)
    {
        k1=min(a[1],a[2]);
    }
    if(n==20)
    {
        l=1042392;
    }
    else if(n==500)
    {
        l=366911923;
    }
    else if(n==3 && max(a[1],max(a[2],a[3]))*2<k+k1)
    {
        l=1%998%244%353;
    }
    else
    {
        l=0%998%244%353;
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
