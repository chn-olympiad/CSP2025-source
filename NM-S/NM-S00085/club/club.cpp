#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][4],sum[4],kid[100005],cnt[4];
vector<int>b;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        sum[1]=sum[2]=sum[3]=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        b.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        for(int i=1;i<=n;i++)
            if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])
            {
                sum[1]+=a[i][1];
                kid[i]=1;
                cnt[1]++;
            }
            else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3])
            {
                sum[2]+=a[i][2];
                kid[i]=2;
                cnt[2]++;
            }
            else
            {
                sum[3]+=a[i][3];
                kid[i]=3;
                cnt[3]++;
            }
        if(cnt[1]>n/2)
        {
            for(int i=1;i<=n;i++)
                if(kid[i]==1)
                    b.push_back(a[i][1]-max(a[i][2],a[i][3]));
            sort(b.begin(),b.end());
            for(int i=0;i<cnt[1]-n/2;i++)
                sum[1]-=b[i];
        }
        else if(cnt[2]>n/2)
        {
            for(int i=1;i<=n;i++)
                if(kid[i]==2)
                    b.push_back(a[i][2]-max(a[i][1],a[i][3]));
            sort(b.begin(),b.end());
            for(int i=0;i<cnt[2]-n/2;i++)
                sum[2]-=b[i];
        }
        else if(cnt[3]>n/2)
        {
            for(int i=1;i<=n;i++)
                if(kid[i]==3)
                    b.push_back(a[i][3]-max(a[i][1],a[i][2]));
            sort(b.begin(),b.end());
            for(int i=0;i<cnt[3]-n/2;i++)
                sum[3]-=b[i];
        }
        printf("%d\n",sum[1]+sum[2]+sum[3]);
    }
    return 0;
}
