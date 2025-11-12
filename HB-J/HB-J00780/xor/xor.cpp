#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,x,a1=0,a2=0;
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==1)
        {

            a1++;
        }
        else
        {
            a2++;
        }
    }
    if(x==0)
    {
        cout<<n/2;
    }
    else
    {
        cout<<a1+a2/2;
    }
    return 0;
}
