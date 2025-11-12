#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
int n,a[maxn][5],T,cha[maxn][5],cha2[maxn];//,dp[maxn]
int t[5],cho;
ll sum;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(t,0,sizeof(t));
        memset(cha,0x3f,sizeof(cha));
        sum=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(a[i][1] >= a[i][2] && a[i][1] >= a[i][3])
            {
                ++t[1];
                cha[i][1]=a[i][1]-max(a[i][2],a[i][3]);
                sum+=a[i][1];
                continue;
            }
            if(a[i][2] >= a[i][1] && a[i][2] >= a[i][3])
            {
                ++t[2];
                sum+=a[i][2];
                cha[i][2]=a[i][2]-max(a[i][1],a[i][3]);
                continue;
            }
            sum+=a[i][3];
            cha[i][3]=a[i][3]-max(a[i][1],a[i][2]);
            ++t[3];
        }
        if(t[1]>=t[2] && t[1]>=t[3])
        {
            cho=1;
        }
        else if(t[2]>=t[1] && t[2]>=t[3])
        {
            cho=2;
        }
        else
        {
            cho=3;
        }
        //printf("%d %d %d cho=%d sum=%d\n",t[1],t[2],t[3],cho,sum);
        if(t[cho]<=n/2)
        {
            printf("%lld\n",sum);
            continue;
        }
        int m=t[cho]-n/2;
        //for(int i=1;i<=n;++i)
        //{
        //    cha[i]=a[i][cho]-max(a[i][cho%3 + 1],a[i][ (cho+1) %3 + 1]);
        //}
        for(int i=1;i<=n;++i)
        {
            cha2[i]=cha[i][cho];
        }
        sort(cha2+1,cha2+n+1);
        for(int i=1;i<=m;++i)
        {
            sum-=cha2[i];
        }
        printf("%lld\n",sum);
    }

}

