#include<bits/stdc++.h>
using namespace std;
long long t,n,h[100500];
struct zzh
{
    long long a,b,c,k;
};
zzh a[100500];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long sum=0,d=0,e=0,f=0,g=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c)
            {
                a[i].k=1;
                d++;
                sum+=a[i].a;
            }
            else if(a[i].b>=a[i].a&&a[i].b>=a[i].c)
            {
                a[i].k=2;
                e++;
                sum+=a[i].b;
            }
            else
            {
                a[i].k=3;
                f++;
                sum+=a[i].c;
            }
        }
        if(e<=n/2&&f<=n/2&&d<=n/2)
        {
            cout<<sum<<endl;
        }
        else if(d>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i].k==1)
                {
                    g++;
                    h[g]=min(a[i].a-a[i].c,a[i].a-a[i].b);
                }
            }
            sort(h+1,h+1+g);
            for(int i=1;i<=d-n/2;i++)
            {
                sum-=h[i];
            }
            cout<<sum<<endl;
        }
        else if(e>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i].k==2)
                {
                    g++;
                    h[g]=min(a[i].b-a[i].a,a[i].b-a[i].c);
                }
            }
            sort(h+1,h+1+g);
            for(int i=1;i<=e-n/2;i++)
            {
                sum-=h[i];
            }
            cout<<sum<<endl;
        }
        else if(f>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i].k==3)
                {
                    g++;
                    h[g]=min(a[i].c-a[i].b,a[i].c-a[i].a);
                }
            }
            sort(h+1,h+1+g);
            for(int i=1;i<=f-n/2;i++)
            {
                sum-=h[i];
            }
            cout<<sum<<endl;
        }
    }
}