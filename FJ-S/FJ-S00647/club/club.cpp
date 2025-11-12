#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;

int T,n;

struct node{
    int a1,a2,a3,d;
}a[N];

bool cmp(node aa,node ab)
{
    return aa.d>ab.d;
}

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    scanf("%lld",&T);
    while (T--)
    {
        scanf("%lld",&n);
        memset(a,0,sizeof a);
        for (int i=1;i<=n;i++) scanf("%lld %lld %lld",&a[i].a1,&a[i].a2,&a[i].a3);
        int q1=0,q2=0,q3=0,ans=0;
        for (int i=1;i<=n;i++)
        {
            int a1=a[i].a1,a2=a[i].a2,a3=a[i].a3;
            if (a1>=a2 && a1>=a3) q1++,ans+=a1;
            else if (a2>=a1 && a2>=a3) q2++,ans+=a2;
            else if (a3>=a1 && a3>=a2) q3++,ans+=a3;
        }
        if (q1<=n/2 && q2<=n/2 && q3<=n/2){printf("%lld\n",ans);continue;}
        if (q1>n/2) for (int i=1;i<=n;i++) a[i].d=max(0ll,a[i].a1-max(a[i].a2,a[i].a3));
        if (q2>n/2) for (int i=1;i<=n;i++) a[i].d=max(0ll,a[i].a2-max(a[i].a1,a[i].a3));
        if (q3>n/2) for (int i=1;i<=n;i++) a[i].d=max(0ll,a[i].a3-max(a[i].a2,a[i].a1));
        sort(a+1,a+n+1,cmp);
        for (int i=n/2+1;i<=n;i++) ans-=a[i].d;
        printf("%lld\n",ans);
    }


    return 0;
}