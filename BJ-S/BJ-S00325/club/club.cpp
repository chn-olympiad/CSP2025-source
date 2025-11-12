#include <iostream>
#include <algorithm>
using namespace std;
int a[100005][3],p[100005];
int max3(int i)
{
    int m1=a[i][1],m2=1;
    if(a[i][2]>m1)
        m1=a[i][2],m2=2;
    if(a[i][3]>m1)
        m1=a[i][3],m2=3;
    return m2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,m,g[4],ans=0,dq,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        g[1]=g[2]=g[3]=ans=dq=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            m=max3(i);
            g[m]++,ans+=a[i][m];
        }
        if(g[1]>n/2)
        {
            for(i=1;i<=n;i++)
                if(max3(i)==1)
                {
                    dq++;
                    p[dq]=a[i][1]-max(a[i][2],a[i][3]);
                }
            sort(p+1,p+dq+1);
            for(i=1;i<=dq-n/2;i++)
                ans-=p[i];
            printf("%d\n",ans);
            continue;
        }
        if(g[2]>n/2)
        {
            for(i=1;i<=n;i++)
                if(max3(i)==2)
                {
                    dq++;
                    p[dq]=a[i][2]-max(a[i][1],a[i][3]);
                }
            sort(p+1,p+dq+1);
            for(i=1;i<=dq-n/2;i++)
                ans-=p[i];
            printf("%d\n",ans);
            continue;
        }
        if(g[3]>n/2)
        {
            for(i=1;i<=n;i++)
                if(max3(i)==3)
                {
                    dq++;
                    p[dq]=a[i][3]-max(a[i][1],a[i][2]);
                }
            sort(p+1,p+dq+1);
            for(i=1;i<=dq-n/2;i++)
                ans-=p[i];
            printf("%d\n",ans);
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}