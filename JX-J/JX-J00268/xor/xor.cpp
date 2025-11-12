#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        if(k==1)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(n!=1)
    {
        if(k==0)
        {
            for(int i=0;i<n;i++)
            {
                if(a[i]==0)
                {
                    ans++;
                }
            }
            cout<<ans;
        }
        else if(k==1)
        {
            for(int i=0;i<n;i++)
            {

                if(a[i]==1)
                {
                    ans++;
                }
            }
            cout<<ans;
        }
    }
    return 0;
}
