#include<bits/stdc++.h>
using namespace std;
int a[100010][5],d[5][100010],p[100010],cnt[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,x,y,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt[1]=cnt[2]=cnt[3]=sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                x=a[i][1];
                p[i]=1;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                x=a[i][2];
                p[i]=2;
            }
            else
            {
                x=a[i][3];
                p[i]=3;
            }
            cnt[p[i]]++;
            sum+=x;
            if((a[i][1]>=a[i][2]&&a[i][1]<=a[i][3])||(a[i][1]<=a[i][2]&&a[i][1]>=a[i][3]))y=a[i][1];
            else if((a[i][2]>=a[i][1]&&a[i][2]<=a[i][3])||(a[i][2]<=a[i][1]&&a[i][2]>=a[i][3]))y=a[i][2];
            else y=a[i][3];
            d[p[i]][cnt[p[i]]]=x-y;
        }
        for(int i=1;i<=3;i++)
        {
            if(cnt[i]>n/2)
            {
                sort(d[i]+1,d[i]+cnt[i]+1);
                for(int j=1;j<=cnt[i]-n/2;j++)sum-=d[i][j];
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
