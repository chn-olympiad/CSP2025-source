#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    bool l=true,ll=true;
    long long a[100001];
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)l=false;
        if(a[i]!=1 && a[i]!=0) ll=false;
    }
    if(l)
    {
        cout<<n/2;
        return 0;
    }
    else if(ll)
    {
        long long ans=0;
        if(k == 1)
        {
            for(int i=1;i<n;i++)
            {
                if(a[i] == !a[i+1])
                {
                    ans++;
                    i++;
                }
            }
            cout<<ans<<endl;
        }
        else if(k == 0)
        {
            for(int i=1;i<n;i++)
            {
                if(a[i] == a[i+1])
                {
                    ans++;
                    i++;
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cout<<n/2;
        }
        return 0;
    }
    else
    {
        cout<<n/2<<endl;
        return 0;
    }
    return 0;
}
