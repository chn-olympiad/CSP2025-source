#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i,n,k;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        cout<<1;
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        while(n>0)
        {
            b[i]=a[i]%2;
        }
    }
    return 0;
}
