#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int cha[N],id[N],cnt[N];
int ax[N],ay[N],az[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(cha,0,sizeof(cha));
        memset(id,0,sizeof(id));
        memset(cnt,0,sizeof(cnt));
        memset(ax,0,sizeof(ax));
        memset(ay,0,sizeof(ay));
        memset(az,0,sizeof(az));
        int n;
        cin>>n;
        int ans=0,q=0;
        for(int i=1;i<=n;i++)
        {
            cin>>ax[i]>>ay[i]>>az[i];
            int maxx=ax[i];
            if(ay[i]>maxx)
            {
                maxx=ay[i];
            }
            if(az[i]>maxx)
            {
                maxx=az[i];
            }
            int minn=ax[i];
            if(ay[i]<minn)
            {
                minn=ay[i];
            }
            if(az[i]<minn)
            {
                minn=az[i];
            }
            int tot=ax[i]+ay[i]+az[i];
            cha[i]=maxx+maxx+minn-tot;
            if(maxx==ax[i])
            {
                id[i]=1;
            }
            else if(maxx==ay[i])
            {
                id[i]=2;
            }
            else
            {
                id[i]=3;
            }
            cnt[id[i]]++;
            ans+=maxx;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        if(cnt[1]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==1&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=2;
                q+=sum;
                cnt[1]--;
        }
        else if(cnt[2]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==2&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=3;
                q+=sum;
                cnt[2]--;
        }
        else if(cnt[3]>n/2)
        {
                int sum=INT_MAX,k=1;
                for(int i=1;i<=n;i++)
                {
                    if(id[i]==3&&cha[i]<sum)
                    {
                        sum=cha[i];
                        k=i;
                    }
                }
                id[k]=1;
                q+=sum;
                cnt[3]--;
        }
        cout<<ans-q<<'\n';
    }
    return 0;
}
