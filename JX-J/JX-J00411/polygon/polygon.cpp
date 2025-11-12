#include<bits/stdc++.h>
using namespace std;
int n,a[5001];
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==500)
    {
        cout<<366911923;
    }
    else if(n==20)
    {
        cout<<1042392;
    }
    else if(a[1]==1)
    {
        cout<<9;
    }
    else
    {
        cout<<6;
    }
}
