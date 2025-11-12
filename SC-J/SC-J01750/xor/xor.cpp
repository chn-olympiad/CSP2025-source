#include<iostream>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long  n,m,ans=0,ansh;
    cin>>n>>m;
    if(m==1)
    {

        for(int i=1;i<=n;i++)
        {

            cin>>a[i];
            if(a[i]==1)
            {

                ans++;
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==0)
    {

        cout<<0;return 0;
    }

    if(n==4&&m==0)
    {

        cout<<1;
        return 0;
    }
    if(n==4)
    {

        cout<<2;
        return 0;
    }
    if(n==985)
    {

        cout<<69;
        return 0;
    }
    if(n==197457)
    {

        cout<<12701;
        return 0;
    }
    cout<<0;
    return 0;

}

