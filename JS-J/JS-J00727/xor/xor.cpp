#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int f=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) f=0; 
    }
    if(f==1)
    {
        if(d==1) cout<<n;
        else if(d==0) cout<<n/2;
        else cout<<0;
    }
    else
    {
        int ans=0;
        if(d==0)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0) ans++;
                if(a[i]==1&&a[i+1]==1)
                {
                    ans++;
                    a[i+1]=2;
                }
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ans++;
            }
        }
        cout<<ans;
    }
    return 0;
}