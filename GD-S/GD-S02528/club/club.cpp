#include<cstdio>
#include<queue>
using namespace std;
#define LL long long
const int N=1e6+10;
int T,n,a[N][3];
int s0,s1,s2;
priority_queue<int>t[3];
LL ans;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        while(t[0].size()>0) t[0].pop();
        while(t[1].size()>0) t[1].pop();
        while(t[2].size()>0) t[2].pop();
        ans=0,s0=s1=s2=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
            if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2])
            {
                s0++,ans+=a[i][0];
                t[0].push(max(a[i][1],a[i][2])-a[i][0]);
            }
            else if(a[i][1]>=a[i][2])
            {
                s1++,ans+=a[i][1];
                t[1].push(max(a[i][0],a[i][2])-a[i][1]);
            }
            else
            {
                s2++,ans+=a[i][2];
                t[2].push(max(a[i][0],a[i][1])-a[i][2]);
            }
        }
        if(s0>n/2)
        {
            while(s0>n/2)
            {
                ans+=t[0].top();
                t[0].pop(),s0--;
            }
        }
        if(s1>n/2)
        {
            while(s1>n/2)
            {
                ans+=t[1].top();
                t[1].pop(),s1--;
            }
        }
        if(s2>n/2)
        {
            while(s2>n/2)
            {
                ans+=t[2].top();
                t[2].pop(),s2--;
            }
        }
        printf("%lld\n",ans);
    }
}
