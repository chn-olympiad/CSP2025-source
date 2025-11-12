#include<bits/stdc++.h>
using namespace std;
long long n,k;
struct fanwei
{
    int l,r;
};
fanwei w[1000005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int a[n+2],b[n+2];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        b[i]=a[i]^b[i-1];//qian zhui he
    }
    int shulian=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=1;j--)
        {
            if(j!=1)
            {
                int ank=b[i]^b[j-1];
                if(ank==k)
                {
                    shulian++;
                    w[shulian].l=j;
                    w[shulian].r=i;//fan wei
                }
            }
            else if(b[i]==k)
            {
                shulian++;
                w[shulian].l=j;
                w[shulian].r=i;//fan wei
            }
        }
    }//qiu qu suo you
    if(shulian==0)
    {
        cout<<0;
    }
    else
    {
        int ans=1,e=w[1].r;

        for(int i=2;i<=shulian;i++)
        {
            if(w[i].l>e)
            {
                ans++;
                e=w[i].r;
            }
        }
        cout<<ans;
    }

}
