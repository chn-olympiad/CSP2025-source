#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int t,n;
int a[100005][4];
int f[100005];
int cnt0,cnt1,cnt2;
int g[100005];
int m;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        m=0;
        cnt0=0;
        cnt1=0;
        cnt2=0;
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][0]>>a[i][1]>>a[i][2];
            if(a[i][0]>=a[i][1] && a[i][0]>=a[i][2])
            {
                ans+=a[i][0];
                f[i]=0;
                cnt0++;
            }
            else if(a[i][1]>=a[i][0] && a[i][1]>=a[i][2])
            {
                ans+=a[i][1];
                f[i]=1;
                cnt1++;
            }
            else
            {
                ans+=a[i][2];
                f[i]=2;
                cnt2++;
            }
        }
        if(cnt0>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(f[i]==0)
                {
                    g[++m]=a[i][0]-max(a[i][1],a[i][2]);
                }
            }
            sort(g+1,g+1+m);
            for(int i=1;i<=cnt0-n/2;i++)
            {
                ans-=g[i];
            }
        }
        else if(cnt1>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(f[i]==1)
                {
                    g[++m]=a[i][1]-max(a[i][2],a[i][0]);
                }
            }
            sort(g+1,g+1+m);
            for(int i=1;i<=cnt1-n/2;i++)
            {
                ans-=g[i];
            }
        }
        else if(cnt2>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(f[i]==2)
                {
                    g[++m]=a[i][2]-max(a[i][1],a[i][0]);

                }
            }
            sort(g+1,g+1+m);
            for(int i=1;i<=cnt2-n/2;i++)
            {
                ans-=g[i];
            }
        }
        cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
