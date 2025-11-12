#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,b[5005],x=0,z=0,y=0;
    cin>>a;
    for(int i=1;i<=a;i++)
    {
        cin>>b[i];
    }
    for(int i=1;i<=a;i++)
    {
        x+=b[i];
    }
    for(int i=1;i<=a;i++)
    {
        if(b[i]>=z)
        {
           z=b[i];
        }
    }
    if(x>z*2)
    {
        cout<<998244353%2;
    }
    return 0;
}
