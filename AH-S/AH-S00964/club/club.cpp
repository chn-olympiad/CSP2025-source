#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long

const int N=1e5+5;
int n,t;
int a[N],b[N],c[N];
int ans,flag=0;
int x;

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int o=1;o<=t;o++)
    {
        cin>>n;
        int n0=n>>1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]==0&&c[i]==0)
            {
                flag=1;
            }
            else
            {
                flag=0;
            }
        }
        if(n==2)
        {
            ans=ans+max(a[1],b[1],c[1]);
            ans=ans+max(a[2],b[2],c[2]);
            cout<<ans<<endl;
            continue;
        }
        if(n==4)
        {
            x=a[1]+a[2]+b[3]+c[3];
            ans=max(ans,x);
            x=a[1]+a[2]+b[3]+c[4];
            ans=max(ans,x);
            x=a[1]+a[3]+b[2]+c[4];
            ans=max(ans,x);
            x=a[1]+a[3]+b[4]+c[2];
            ans=max(ans,x);
            x=a[1]+a[4]+b[2]+c[3];
            ans=max(ans,x);
            x=a[1]+a[4]+b[3]+c[2];
            ans=max(ans,x);

            x=a[1]+b[2]+b[3]+c[4];
            ans=max(ans,x);
            x=a[1]+b[2]+c[3]+b[4];
            ans=max(ans,x);
            x=a[1]+c[2]+b[3]+b[4];
            ans=max(ans,x);
            x=a[1]+b[2]+c[3]+c[4];
            ans=max(ans,x);
            x=a[1]+c[2]+b[3]+c[4];
            ans=max(ans,x);
            x=a[1]+c[2]+c[3]+b[4];
            ans=max(ans,x);


            x=b[1]+b[2]+a[3]+c[3];
            ans=max(ans,x);
            x=b[1]+b[2]+a[3]+c[4];
            ans=max(ans,x);
            x=b[1]+b[3]+a[2]+c[4];
            ans=max(ans,x);
            x=b[1]+b[3]+a[4]+c[2];
            ans=max(ans,x);
            x=b[1]+b[4]+a[2]+c[3];
            ans=max(ans,x);
            x=b[1]+b[4]+a[3]+c[2];
            ans=max(ans,x);

            x=b[1]+a[2]+a[3]+c[4];
            ans=max(ans,x);
            x=b[1]+a[2]+c[3]+a[4];
            ans=max(ans,x);
            x=b[1]+c[2]+a[3]+a[4];
            ans=max(ans,x);
            x=b[1]+a[2]+c[3]+c[4];
            ans=max(ans,x);
            x=a[1]+c[2]+b[3]+c[4];
            ans=max(ans,x);
            x=b[1]+c[2]+c[3]+a[4];
            ans=max(ans,x);


            x=c[1]+c[2]+b[3]+a[3];
            ans=max(ans,x);
            x=c[1]+c[2]+b[3]+a[4];
            ans=max(ans,x);
            x=c[1]+c[3]+b[2]+a[4];
            ans=max(ans,x);
            x=c[1]+c[3]+b[4]+a[2];
            ans=max(ans,x);
            x=c[1]+c[4]+b[2]+a[3];
            ans=max(ans,x);
            x=c[1]+c[4]+b[3]+a[2];
            ans=max(ans,x);

            x=c[1]+b[2]+b[3]+a[4];
            ans=max(ans,x);
            x=c[1]+b[2]+a[3]+b[4];
            ans=max(ans,x);
            x=c[1]+a[2]+b[3]+b[4];
            ans=max(ans,x);
            x=c[1]+b[2]+a[3]+a[4];
            ans=max(ans,x);
            x=c[1]+a[2]+b[3]+a[4];
            ans=max(ans,x);
            x=c[1]+a[2]+a[3]+b[4];
            ans=max(ans,x);

            cout<<ans<<endl;
            continue;
        }
        if(flag==1)
        {
            sort(a,a+1,a+1+n);
            for(int i=n+1;i>=n0;i--)
            {
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        }
    }
    return 0;
}
