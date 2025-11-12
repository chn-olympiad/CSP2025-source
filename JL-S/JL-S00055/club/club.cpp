#include<bits/stdc++.h>
#define N 100005
using namespace std;
int T,n,a[N][3],sum[3],op[N],val[N],pos[N];
bool cmp(int i,int j)
{
    return val[i]<val[j];
}
void work()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&n);
    int ans=0;
    sum[0]=sum[1]=sum[2]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
        if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
            ans+=a[i][0],op[i]=0,sum[0]++,val[i]=a[i][0]-max(a[i][1],a[i][2]);
        else if(a[i][1]>=a[i][0]&&a[i][1]>=a[i][2])
            ans+=a[i][1],op[i]=1,sum[1]++,val[i]=a[i][1]-max(a[i][0],a[i][2]);
        else
            ans+=a[i][2],op[i]=2,sum[2]++,val[i]=a[i][2]-max(a[i][0],a[i][1]);
    }
    int Op=-1;
    if(sum[0]>n/2) Op=0;
    else if(sum[1]>n/2) Op=1;
    else if(sum[2]>n/2) Op=2;
    if(Op==-1)
    {
        printf("%d\n",ans);
        return ;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(op[i]==Op)
            pos[++cnt]=i;
    sort(pos+1,pos+1+cnt,cmp);
    for(int i=1;i<=sum[Op]-n/2;i++)
        ans-=val[pos[i]];
    printf("%d\n",ans);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        work();
    }
    return 0;
}