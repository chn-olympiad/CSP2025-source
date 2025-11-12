#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct node
{
    int maxx,midx,minx;
    int maxid,midid,minid;
}a[100010];
bool cmp(node x,node y)
{
    if(x.maxid!=y.maxid)    return x.maxid<y.maxid;
    return x.maxx-x.midx<y.maxx-y.midx;
}
int n,sum,cnt[5],last[5];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        sum=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        last[1]=last[2]=last[3]=0;
        for(int i=1;i<=n;i++)
        {
            int fir,sec,thr,id1=1,id2=2,id3=3;
            scanf("%d%d%d",&fir,&sec,&thr);
            if(sec>fir)
            {
                swap(sec,fir);
                swap(id1,id2);
            }
            if(thr>fir)
            {
                swap(thr,fir);
                swap(id1,id3);
            }
            if(thr>sec)
            {
                swap(sec,thr);
                swap(id2,id3);
            }
            a[i]=node{fir,sec,thr,id1,id2,id3};
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
            cnt[a[i].maxid]++;
            sum+=a[i].maxx;
        }
        if(cnt[1]<=n/2&&cnt[2]<=n/2&&cnt[3]<=n/2)
        {
            printf("%d\n",sum);
            continue;
        }
        for(int i=n;i>=1;i--)
        {
            last[a[i].maxid]=i;
        }
        int more;
        if(cnt[1]>n/2)    more=1;
        else if(cnt[2]>n/2)   more=2;
        else    more=3;
        for(int i=last[more];i<=last[more]+(cnt[more]-n/2)-1;i++)
        {
            sum-=(a[i].maxx-a[i].midx);
        }
        printf("%d\n",sum);
    }
    return 0;
}
