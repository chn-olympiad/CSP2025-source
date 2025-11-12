#include<bits/stdc++.h>
using namespace std;
int f[205][205][205],a[100005][4];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cin>>n;
        bool flag=0;
        for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3],flag|=a[i][3];
        if(n<=200)
        {
                for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    for(int k=0;k<=n;k++)f[i][j][k]=0;
            for(int i=1;i<=n;i++)
                for(int j=min(i,n/2);j>=0;j--)
                    for(int k=min(i-j,n/2);k>=0;k--)
                    {
                        if(j>=1)
                        f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]+a[i][1]);
                        if(k>=1)
                        f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+a[i][2]);
                        if(j+k<i)
                        f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[i][3]);
                    }
            for(int j=0;j<=n/2;j++)
                for(int k=0;k<=n/2;k++)
                {
                    if(j+k>=n/2)ans=max(ans,f[n][j][k]);
                }
            cout<<ans<<'\n';
        }
        if(flag==0)
        {
            int t1[50010],t2[50010];
            for(int i=1;i<=n;i++)
            {
                if(i<=n/2)ans+=a[i][1],t1[i]=a[i][2]-a[i][1];
                else ans+=a[i][2],t2[i-n/2]=a[i][1]-a[i][2];
            }
            sort(t1+1,t1+n/2+1);
            sort(t2+1,t2+n/2+1);
            for(int i=n/2;i>=1;i--)
                if(t1[i]+t2[i]>0)ans+=t1[i]+t2[i];
            cout<<ans<<'\n';
        }
    }
    return 0;
}