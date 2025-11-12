#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans=0,jx0=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if (k==0)
    {
        for (int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                jx0++;
                ans+=jx0;
            }
            else{
                jx0=0;
            }
        }
        cout<<ans;
        return 0;
    }

    return 0;
}
