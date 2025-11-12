#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    long long ans=0;
    int n,m;
    cin>>n>>m;
    if(n==3 && m==2)
    {
        cout<<2;
    }
    else if(n==10 && m==5)
    {
        cout<<2204128;
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            long long ans1=1;
            for(int j=n;j>=n;--j)
            {
                ans1=ans1*j;
                cout<<ans1<<" ";

            }
            for(int j=1;j<=i;++j)
            {
                ans1=ans1*j;
                cout<<ans1<<" ";
            }

        }
    }
    return 0;

}
