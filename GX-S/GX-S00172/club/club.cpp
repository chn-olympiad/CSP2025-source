#include<bits/stdc++.h>
using namespace std;
int like[100002][4],ans,c1[100002],sum[4],c2[100002];
int n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    for(int time=1;time<=t;time++)
    {
        memset(like,0,sizeof(like));
        ans=0;
        cin >>n;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin >>like[i][j];
            }
            ans+=like[i][1];
            c1[i]=like[i][1]-like[i][2];c2[i]=like[i][1]-like[i][3];

        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n-i+1;j++)
            {
                if(min(c1[j],c2[j])>min(c1[j+1],c2[j+1]))
                {
                    swap(c1[j],c1[j+1]);
                    swap(c2[j],c2[j+1]);
                }
            }
        }
        sum[1]=n/2;
            for(int i=1;i<=n/2;i++)
            {
                ans-=min(c1[i],c2[i]);
                if(c1[i]>c2[i])
                    sum[2]++;
                else
                    sum[3]++;
            }
            for(int i=n/2+1;i<=n&&min(c1[i],c2[i])<0;i++)
            {
                if(sum[2]>=n/2&&c2[i]<0)
                {
                    ans-=c2[i];
                    sum[2]++;
                }

                else if(sum[3]>=n/2&&c1[i]<0)
                {
                    ans-=c1[i];
                    sum[3]++;
                }
                else if(sum[2]<n/2&&c1[i]<c2[i])
                {
                    ans-=c1[i];
                    sum[2]++;
                }
                else if(sum[3]<n/2&&c2[i]<c1[i])
                {
                    ans-=c2[i];
                    sum[3]++;
                }
            }
            cout<<ans<<endl;

    }
    return 0;
}



























