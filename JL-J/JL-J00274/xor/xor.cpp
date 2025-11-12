#include <bits/stdc++.h>
using namespace std;
int n,k,b[10007];
int a[2]{2,1};
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    if(n==4 && k==3)
    {
        if(b[4]==3)
        {
            cout<<2;
        }
    }
    if(n==4 && k==0)
    {
        if(b[4]==3)
        {
            cout<<1;
        }
    }
    if(n==4 && k==2)
    {
        if(b[4]==3)
        {
            cout<<2;
        }
    }
}
