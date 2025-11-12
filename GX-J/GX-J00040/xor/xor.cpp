#include <bits/stdc++.h>
using namespace std;

int a[500001],n,k;
bool vis[500001];

int ws(int x)
{
    int w=0;
    while(x>0)
    {
        x/=2;
        w++;
    }
    return w;
}

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);

    cin>>n>>k;
    int bs=-1,mx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>1)  bs=3;
        if(a[i]==1)
        {
            if(bs==-1)  bs=1;
            else if(bs==0)  bs=2;
        }
        if(a[i]==0)
        {
            if(bs==-1)  bs=0;
            else if(bs==1)  bs=2;
        }
        if(a[i]>mx) mx=a[i];
    }

    if(ws(mx)<ws(k))
    {
        cout<<0<<endl;
        return 0;
    }
    if(bs<3)
    {
        if(bs==0)
        {
            if(k==0)    cout<<n<<endl;
            else    cout<<0<<endl;
        }
        if(bs==1)
        {
            if(k==0)    cout<<n/2<<endl;
            else if(k==1)    cout<<n<<endl;
            else    cout<<0<<endl;
        }
        if(bs==2)
        {
            if(k==0)
            {
                int ans=0,ls=0;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==0)
                    {
                        ans++;
                        ls=0;
                    }
                    else
                    {
                        if(ls==0)   ls++;
                        else{
                            ans++;
                            ls=0;
                        }
                    }
                }
                cout<<ans<<endl;
            }
            else if(k==1)
            {
                int ans=0;
                for(int i=1;i<=n;i++)
                {
                    if(a[i]==1) ans++;
                }
                cout<<ans<<endl;
            }
            else    cout<<0<<endl;
        }
        return 0;
    }

    int ans=0,za,f;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==k)
        {
            ans++;
            vis[i]=1;
            continue;
        }
        int x=a[i];
        for(int j=i-1;j>0;j--)
        {
            if(vis[j]==1)   break;
            x^=a[j];
            if(x==k)
            {
                for(int k=i;k>=j;k--) vis[k]=1;
                ans++;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
