#include <bits/stdc++.h>
using namespace std;

long long n,k,a[500005],b,l,r,t,ans=0,d=0,f;
int e[500005][22]={},c[22],s[22]={};

void Xor (int a[],int b[],int c[])
{
    for (int i=1;i<=21;i++)
    {
        if (a[i]==b[i])
        {
            c[i]=0;
        }
        else
        {
            c[i]=1;
        }
    }
    return ;
}

int main ()
{
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        b=a[i];
        t=0;
        while (b>0)
        {
            t++;
            e[i][22-t]=b%2;
            b=b/2;
        }
    }
    t=0;
    while (k>0)
    {
        t++;
        s[22-t]=k%2;
        k=k/2;
    }
    l=1;
    r=1;

    while (r<=n)
    {
        for (int i=1;i<=21;i++)
        {
            c[i]=e[r][i];
        }

        f=1;
        for (int i=1;i<=21;i++)
        {
            if (s[i]!=c[i])
            {
                f=0;
                break;
            }
        }
        if (f==1)
        {
            ans++;
            r++;
            l=r;
        }
        else
        {
            for (int j=r-1;j>=l;j--)
            {
                Xor (c,e[j],c);
                f=1;
                for (int i=1;i<=21;i++)
                {
                    if (s[i]!=c[i])
                    {
                        f=0;
                        break;
                    }
                }
                if (f==1)
                {
                    //cout<<l<<" "<<r<<endl;
                    ans++;
                    l=r+1;
                    break;
                }
            }
            r++;
        }


    }
    cout<<ans;
    return 0;
}
