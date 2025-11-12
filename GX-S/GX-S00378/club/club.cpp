#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int N=100005;
int T,n;
struct node{ll a1,a2,id1,id2;}a[N];
bool cmp(node x,node y)
{
    return x.a1-x.a2>y.a1-y.a2;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            if(x>=y&&x>=z)
            {
                a[i].a1=x,a[i].id1=1;
                if(y>=z) a[i].a2=y,a[i].id2=2;
                else a[i].a2=z,a[i].id2=3;
            }
            else if(y>=z)
            {
                a[i].a1=y,a[i].id1=2;
                if(x>=z) a[i].a2=x,a[i].id2=1;
                else a[i].a2=z,a[i].a2=3;
            }
            else
            {
                a[i].a1=z,a[i].id1=3;
                if(x>=y) a[i].a2=x,a[i].id2=1;
                else a[i].a2=y,a[i].id2=2;
            }
        }
        sort(a+1,a+n+1,cmp);
        ll ans=0,cnt[4]={0,0,0,0},m=n/2;
        for(int i=1;i<=n;i++)
        {
            if(cnt[a[i].id1]<m) cnt[a[i].id1]++,ans+=a[i].a1;
            else cnt[a[i].id2]++,ans+=a[i].a2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
