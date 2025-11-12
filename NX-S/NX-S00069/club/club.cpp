#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
    return x>y;
}
int a[50][50][50],s[999][999],cnt[1000005],q;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        q=n/2;
        for(int j=1;j<=n;i++)
        {
            for(int k=1;k<=3;j++)
            {
                cin>>a[i][j][k];
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=q;j++)
        {
            for(int k=1;k<=3;k++)
            {
                if(a[i][j][0]>=a[i][j][1]&&a[i][j][0]>=a[i][j][2]&&a[i][j][0]+a[i][j][1]+a[i][j][2]<=n&&s[i][j]<=q)
                {
                    cnt[i]+=a[i][j][0];
                    a[i][j][0]=0;
                    s[i][j]++;
                }
                if(a[i][j][1]>=a[i][j][0]&&a[i][j][1]>=a[i][j][2]&&a[i][j][0]+a[i][j][1]+a[i][j][2]<=n&&s[i][j]<=q)
                {
                    cnt[i]+=a[i][j][1];
                    a[i][j][1]=0;
                    s[i][j]++;
                }
                if(a[i][j][2]>=a[i][j][0]&&a[i][j][2]>=a[i][j][1]&&a[i][j][0]+a[i][j][1]+a[i][j][2]<=n&&s[i][j]<=q)
                {
                    cnt[i]+=a[i][j][2];
                    a[i][j][2]=0;
                    s[i][j]++;
                }
            }
        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<cnt[i]<<endl;
    }
    return 0;
}

