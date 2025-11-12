#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,ans[10];
int n,a[100005],b[100005],c[100005],f[100005][4];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int jntm=1;jntm<=t;jntm++)
    {
        cin>>n;
        int bz=n/2,pd[5]={0};
        for(int i=0;i<n;i++)
        {
            cin>>a[i]>>b[i]>>c[i];
        }
        for(int i=0;i<100005;i++)
        {
            for(int j=0;j<3;j++)
            {
                f[i][j]=0;
            }
        }
        f[0][0]=a[0];f[0][1]=b[0];f[0][2]=c[0];
        for(int j=1;j<n;j++)
        {
            int temp=max(max(f[j-1][0],f[j-1][1]),max(f[j-1][2],f[j-1][1]));
            for(int i=0;i<3;i++)
            {
                if(f[j-1][i]==temp) pd[i]++;
            }
            for(int p=0;p<3;p++)
            {
                if(p==0)
                {
                    f[j][p]=max(max(f[j-1][p],f[j-1][p+1]),max(f[j-1][p+1],f[j-1][p+2]))+a[j];
                }
                if(p==1)
                {
                    f[j][p]=max(max(f[j-1][p],f[j-1][p-1]),max(f[j-1][p],f[j-1][p+1]))+b[j];
                }
                if(p==2)
                {
                    f[j][p]=max(max(f[j-1][p],f[j-1][p-1]),max(f[j-1][p-2],f[j-1][p-2]))+c[j];
                }
            }
        }
        int m1=0,m2=0,m3=0;
        if(pd[0]<=bz&&pd[1]<=bz)
        {
            m1=max(f[n-1][1],f[n-1][0]);
        }
        if(pd[1]<=bz&&pd[2]<=bz)
        {
            m2=max(f[n-1][1],f[n-1][2]);
        }
        if(pd[0]<=bz&&pd[2]<=bz)
        {
            m3=max(f[n-1][2],f[n-1][0]);
        }
        cout<<max(max(m1,m2),max(m2,m3))<<endl;
    }
    return 0;
}
