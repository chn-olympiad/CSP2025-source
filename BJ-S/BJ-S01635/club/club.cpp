#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
struct Node
{
    int x,y,z;
    int a,b,c;
}p[N];
int dif[N];
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>p[i].a>>p[i].b>>p[i].c;
        for(int i=1;i<=n;i++)
        {
            if(p[i].a>=p[i].b&&p[i].a>=p[i].c)
            {
                if(p[i].b>=p[i].c)
                {
                    p[i].x=1;
                    p[i].y=2;
                    p[i].z=3;
                }
                else
                {
                    p[i].x=1;
                    p[i].y=3;
                    p[i].z=2;
                }
            }
            else if(p[i].b>=p[i].a&&p[i].b>=p[i].c)
            {
                if(p[i].a>=p[i].c)
                {
                    p[i].x=2;
                    p[i].y=1;
                    p[i].z=3;
                }
                else
                {
                    p[i].x=2;
                    p[i].y=3;
                    p[i].z=1;
                }
            }
            else
            {
                if(p[i].a>p[i].b)
                {
                    p[i].x=3;
                    p[i].y=1;
                    p[i].z=2;
                }
                else
                {
                    p[i].x=3;
                    p[i].y=2;
                    p[i].z=1;
                }
            }
        }
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++)
        {
            if(p[i].x==1) cnt1++;
            if(p[i].x==2) cnt2++;
            if(p[i].x==3) cnt3++;
        }
        if(max({cnt1,cnt2,cnt3})<=n/2)
        {
            int ans=0;
            for(int i=1;i<=n;i++) ans+=max({p[i].a,p[i].b,p[i].c});
            cout<<ans<<endl;
        }
        else
        {
            int ans=0;
            for(int i=1;i<=n;i++) ans+=max({p[i].a,p[i].b,p[i].c});
            int id=0;
            if(cnt1>n/2) id=1;
            if(cnt2>n/2) id=2;
            if(cnt3>n/2) id=3;
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(p[i].x==id)
                {
                    int X=0;
                    if(p[i].x==1) X+=p[i].a;
                    if(p[i].x==2) X+=p[i].b;
                    if(p[i].x==3) X+=p[i].c;
                    if(p[i].y==1) X-=p[i].a;
                    if(p[i].y==2) X-=p[i].b;
                    if(p[i].y==3) X-=p[i].c;
                    dif[++cnt]=X;
                }
            }
            sort(dif+1,dif+cnt+1);
            for(int i=1;i<=(cnt-n/2);i++) ans-=dif[i];
            cout<<ans<<endl;
        }
    }
    return 0;
}
