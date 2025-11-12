#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005],c[100005],h[10];
bool px(long long a,long long b)
{
    return a>b;
}
int main()
{
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
long long t,n;
cin>>t;
for(int i=1;i<=t;i++)
    {
        cin>>n;
        long long z=0,maxz=0;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
        if(n==2)
            {
                h[1]=a[1]+b[2];
                h[2]=a[1]+c[2];
                h[3]=b[1]+a[2];
                h[4]=b[1]+c[2];
                h[5]=c[1]+a[2];
                h[6]=c[1]+b[2];
                for(int i=1;i<=6;i++)
                    {
                        if(h[i]>maxz)maxz=h[i];
                    }
                    cout<<maxz<<endl;return 0;

            }
          else
            {
                sort(a+1,a+1+n,px);
                for(int i=1;i<=n/2;i++)
                    {
                        z+=a[i];
                    }
                cout<<z<<endl;
            }
    }
return 0;
}
