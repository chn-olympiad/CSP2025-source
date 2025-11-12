#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,a[5][100005],b[100005],c[100005],cnt1,cnt2,cnt3,cnt,ans;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cnt=0;
        cnt1=0;
        cnt2=0;
        cnt3=0;
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[1][i]>>a[2][i]>>a[3][i];
            if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i])
            {
                ans+=a[1][i];
                cnt1++;
                b[i]=1;
            }
            else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i])
            {
                ans+=a[2][i];
                cnt2++;
                b[i]=2;
            }
            else
            {
                ans+=a[3][i];
                cnt3++;
                b[i]=3;
            }
        }
        if(cnt1>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(b[i]==1)
                {
                    cnt++;
                    if(a[1][i]-a[2][i]<=a[1][i]-a[3][i])
                    {
                        c[cnt]=a[1][i]-a[2][i];
                    }
                    else
                    {
                        c[cnt]=a[1][i]-a[3][i];
                    }
                }
            }
            sort(c+1,c+cnt+1);
            for(int i=1;i<=cnt1-n/2;i++)
            {
                ans-=c[i];
            }
        }
        else if(cnt2>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(b[i]==2)
                {
                    cnt++;
                    if(a[2][i]-a[1][i]<=a[2][i]-a[3][i])
                    {
                        c[cnt]=a[2][i]-a[1][i];
                    }
                    else
                    {
                        c[cnt]=a[2][i]-a[3][i];
                    }
                }
            }
            sort(c+1,c+cnt+1);
            for(int i=1;i<=cnt2-n/2;i++)
            {
                ans-=c[i];
            }
        }
        else if(cnt3>n/2)
        {
            for(int i=1;i<=n;i++)
            {
                if(b[i]==3)
                {
                    cnt++;
                    if(a[3][i]-a[1][i]<=a[3][i]-a[2][i])
                    {
                        c[cnt]=a[3][i]-a[1][i];
                    }
                    else
                    {
                        c[cnt]=a[3][i]-a[2][i];
                    }
                }
            }
            sort(c+1,c+cnt+1);
            for(int i=1;i<=cnt3-n/2;i++)
            {
                ans-=c[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
