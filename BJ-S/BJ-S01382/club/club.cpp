#include<bits/stdc++.h>
#define ll long long
#define ls x>>1
#define rs x>>1|1
const int N=1e5+5;
ll t,n,m,a[N][5],b[N];
using namespace std;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(b,0,sizeof(b));
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
        ll m=n/2,s1=0,s2=0,s3=0,sum=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])s1++;
            else if(a[i][2]>a[i][3])s2++;
            else s3++;
        }
        for(int i=1;i<=n;i++)sum+=max(a[i][1],max(a[i][2],a[i][3]));
        if(s1<=m&&s2<=m&&s3<=m)
        {
            cout<<sum<<'\n';
        }
        if(s1>m)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i][1]>a[i][2]&&a[i][1]>a[i][3])b[++cnt]=a[i][1]-max(a[i][2],a[i][3]);
            }
            sort(b+1,b+cnt+1);
            for(int i=1;i<=s1-m;i++)sum-=b[i];
            cout<<sum<<'\n';
        }
        if(s2>m)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i][2]>a[i][1]&&a[i][2]>a[i][3])b[++cnt]=a[i][2]-max(a[i][1],a[i][3]);
            }
            sort(b+1,b+cnt+1);
            for(int i=1;i<=s2-m;i++)sum-=b[i];
            cout<<sum<<'\n';
        }
        if(s3>m)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i][3]>a[i][2]&&a[i][3]>a[i][1])b[++cnt]=a[i][3]-max(a[i][2],a[i][1]);
            }
            sort(b+1,b+cnt+1);
            for(int i=1;i<=s3-m;i++)sum-=b[i];
            cout<<sum<<'\n';
        }
    }
    return 0;
}
