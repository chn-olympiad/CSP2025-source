#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int ans=0,t=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1)
        {
            if(a[i-1]==0)
            t++;
            else
            {

                ans=max(t,ans);
                t=0;
            }
        }
    }
    if(a[n]==0)
    {
        t++;

    }
    ans=max(ans,t);
    if(k==0)
    {
        cout<<ans;
        return 0;
    }
    if(k==1)
    {
        cout<<n;
        return 0;
    }
    return 0;
}
