#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,a[500005],i,j,s=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                s++;
            }
        }
    }
    if(k==1)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                s++;
            }
        }
    }
    cout<<s;
    return 0;
}
