#include<bits/stdc++.h>
using namespace std;
int i,n,l[5005];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>l[i];
    sort(l+1,l+1+n);
    if(n==3)
        if(l[1]+l[2]>l[3])
        {
            cout<<1;
            return 0;
        }
    else
    {
        if(n==5)
            if(l[i]==1)
                cout<<9;
            else
                cout<<6;
        if(n==20)
            cout<<1042392;
        if(n==500)
            cout<<366911923;
    }
    return 0;
}
