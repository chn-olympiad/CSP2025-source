#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],l[1000000],r[1000000],k,q,s,ans;
bool f;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i]==0)f=1;
    }
    if(f==0)
    {
        cout<<n/2;
        return 0;
    }
    if(k==0)
    {
        for(int i=1; i<=n; i++)
        {
            if(a[i]==0)ans++;
            if(a[i]==1&&a[i+1]==1)ans++,i+=2;
        }

        cout<<ans;
    }
    if(k==1)
    {
        for(int i=1; i<=n; i++)
        {
            if(a[i]==1)ans++;
        }

        cout<<ans;
    }

    return 0;
}
