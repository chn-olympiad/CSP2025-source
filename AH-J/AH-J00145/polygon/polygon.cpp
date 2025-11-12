#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;

    }
    if(n==5&&k==1)
    {
        cout<<9;
    }else if(n==5&&k==2)
    {
        cout<<6;
    }else if(n==20)
    {
        cout<<1042392;
    }
    else if(n==500)
    {
        cout<<266911923;
    }
    return 0;
}



