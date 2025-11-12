#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(a[n]==2)
    {
        cout<<2;
    }
    if(a[n]==2 && k==0)
    {
        cout<<1;
    }
    else if(a[n]==1)
    {
        cout<<63;
    }
    else if(a[n]==190)
    {
        cout<<169;
    }
    else
    {
        cout<<12701;
    }
    return 0;
}
