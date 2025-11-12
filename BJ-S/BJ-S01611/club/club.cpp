#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],sum[5],ans,num[100005],c[100005],cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        sum[1] = 0;
        sum[2] = 0;
        sum[3] = 0;
        ans = 0;
        cnt = 0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                sum[1]++;
                ans += a[i][1];
                c[i] = 1;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                sum[2]++;
                ans += a[i][2];
                c[i] = 2;
            }
            else if(a[i][3]>=a[i][1]&&a[i][3]>=a[i][2])
            {
                sum[3]++;
                ans += a[i][3];
                c[i] = 3;
            }
        }
        if(sum[1]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(c[i]==1)
                {
                    cnt++;
                    num[cnt] = min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
                }
            }
            sort(num+1,num+cnt+1);
            for(int i=1;i+n/2<=sum[1];i++)
            {
                ans -= num[i];
            }
        }
        if(sum[2]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(c[i]==2)
                {
                    cnt++;
                    num[cnt] = min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
                }
            }
            sort(num+1,num+cnt+1);
            for(int i=1;i+n/2<=sum[2];i++)
            {
                ans -= num[i];
            }
        }
        if(sum[3]>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(c[i]==3)
                {
                    cnt++;
                    num[cnt] = min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
                }
            }
            sort(num+1,num+cnt+1);
            for(int i=1;i+n/2<=sum[3];i++)
            {
                ans -= num[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}