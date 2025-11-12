#include <bits/stdc++.h>
using namespace std;
void lesson1()
{
    int n,k;
    cin>>n>>k;
    int a[n+10];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    if(k==1)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i])
            {
                ans++;
            }
        }
    }
    if(k==0)
    {
        int z=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==0)
            {
                ans++;
            }
            else
            {
                if(z)
                {
                    if(a[i]==1)
                    {
                        ans++;
                        z--;
                    }
                }
                else
                {
                    z=1;
                }
            }
        }
    }
    cout<<ans;
}
int main()
{
    freopen(xor.in,"r",stdin);
    freopen(xor.out,"w",stdout);
    lesson1();
    return 0;
}
