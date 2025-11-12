#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n=0,ans=0,m=0,mx=0;
    long long a[10000];
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        m+=a[i];
        if(mx<a[i])
        {
            mx=a[i];
        }
    }
    if(2*mx<m)
    {
        cout<<"1";
    }
    return 0;
}
