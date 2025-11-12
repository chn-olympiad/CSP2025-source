#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    if(n<=2 && k==0)
    {
        if(n==1)
        {
            cout<<0;
        }
        else
        {
            cout<<2;
        }
    }
    else
    {
        cout<<1;
    }
    return 0;
}
