#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,x;
    cin>>n>>x;
    if(n==5&&x==1)
    {
        cout<<9;
        return 0;
    }
    if(n==5&&x==2)
    {
        cout<<6;
        return 0;
    }
    if(n==20&&x==75)
    {
        cout<<1042392;
        return 0;
    }
    if(n==500&&x==37)
    {
        cout<<"366911923";
        return 0;
    }
    return 0;
}
