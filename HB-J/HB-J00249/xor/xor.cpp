#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool checkA=1,checkB=1;
    a[0]=-1;
    for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        if(a[x]!=1) checkA=0;
        if(a[x]!=1&&a[x]!=0) checkB=0;
    }
    if(checkA==1&&k==0)
    {
        cout<<n/2;
        return 0;
    }
    if(checkB==1)
    {
        if(k==0)
        {
            int l1=0;
            for(int x=1;x<=n;x++)
            {
                if(a[x]==0) ans++;
                if(a[x]==1) l1++;
                if(l1==2&&a[x-1]==1)
                {
                    ans++;
                    l1=0;
                }
            }
        }
        else if(k==1)
        {
            int l0=0;
            for(int x=1;x<=n;x++)
            {
                if(a[x]==1) ans++;
                if(a[x]==0) l0++;
                if(l0==2&&a[x-1]==0)
                {
                    ans++;
                    l0=0;
                }
            }
        }
        cout<<ans;
        return 0;
    }
    return 0;
}
