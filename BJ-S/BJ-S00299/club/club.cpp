#include<bits/stdc++.h>
using namespace std;
long long ans=0;
int ta[100005],tb[100005],tc[100005];
int lena,lenb,lenc;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n,x,y,z;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ans=0;
        lena=lenb=lenc=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if(x>=y&&x>=z)
            {
                ans+=x;
                ta[++lena]=min(x-y,x-z);
            }else if(y>=z)
            {
                ans+=y;
                tb[++lenb]=min(y-x,y-z);
            }else
            {
                ans+=z;
                tc[++lenc]=min(z-x,z-y);
            }
        }
        if(lena<=n/2&&lenb<=n/2&&lenc<=n/2)
        {
            printf("%lld\n",ans);
            continue;
        }
        if(lena>n/2)
        {
            sort(ta+1,ta+lena+1);
            for(int i=1;i<=lena-n/2;i++)
            {
                ans-=ta[i];
            }
            printf("%lld\n",ans);
        }else if(lenb>n/2)
        {
            sort(tb+1,tb+lenb+1);
            for(int i=1;i<=lenb-n/2;i++)
            {
                ans-=tb[i];
            }
            printf("%lld\n",ans);
        }else
        {
            sort(tc+1,tc+lenc+1);
            for(int i=1;i<=lenc-n/2;i++)
            {
                ans-=tc[i];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
