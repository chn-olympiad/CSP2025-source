#include <bits/stdc++.h>
using namespace std;
int a[500005],sum,n,k,p=1,q=0,s0=0,s1=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
        {
            s0++;
            p=0,q=0;
        }
        else if(a[i]==1)
        {
            s1++;
            if(q==1)
            {
                sum++,q=0;
            }
            else q=1;
        }
    }
    if(p==1 && k==0)
    {
        if(n%2==0) cout<<n/2<<endl;
        else cout<<(n-1)/2<<endl;
    }
    else if(p==0 && (k==1||k==0))
    {
        if(k==1) cout<<s1<<endl;
        else cout<<s0+sum<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
