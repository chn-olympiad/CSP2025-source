#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read()
{
    ll s=0,t=1;
    char c=getchar();
    while(c<'0'&&c>'9')
    {
        if(c=='-') t=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {

        s=s*10+c-'0';
        c=getchar();
    }
    return s*t;
}
ll n,k,a[200005];
char c='A';
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int i=1;i<=n;i++)
    {
        a[i]=read();
        if(a[i]==0) c='B';
    }
    if(c=='A')
    {
        cout<<n/2;

    }
    else if(c=='B')
    {
        ll ans=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            sum^=a[i];
            if(sum==k)
            {
                ans++;
                sum=0;
            }
        }
        cout<<ans;
    }
    else
    {
        ll ans=0,sum=0,id=1;
        for(int i=1;i<=n;i++)
        {
            sum^=a[i];

            if(sum==k||a[i]==k)
            {
                id=i;
                ans++;
                sum=0;
            }
            else
            {
                for(int j=id;j<=i-1;j++)
                {
                    ll sum1=sum;
                    sum1^=a[j];
                    if(sum1==k)
                    {
                        id=i;
                        ans++;
                        sum=0;
                    }
                }
            }
        }
    }
    return 0;
}
