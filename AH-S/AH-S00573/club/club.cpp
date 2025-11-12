#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    ll a,b,c,d;
}x[100105];
bool cmp(node x,node y)
{
    return x.d>y.d;
}
ll ans;
ll T,n;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&T);
    while(T--)
    {
        ll cnt1=0,cnt2=0,cnt3=0;
        ans=0;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld %lld %lld",&x[i].a,&x[i].b,&x[i].c);
            ll t1=max(x[i].a,max(x[i].b,x[i].c)),t2=min(x[i].a,min(x[i].b,x[i].c));
            x[i].d=t1-(x[i].a+x[i].b+x[i].c-t1-t2);
            ans+=t1;
        }
        sort(x+1,x+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            ll t1=max(x[i].a,max(x[i].b,x[i].c));
            if(t1==x[i].a)
            {
                cnt1++;
                if(cnt1>n/2)
                {
                    cnt1--;
                    ans-=x[i].d;
                }
            }
            else if(t1==x[i].b)
            {
                cnt2++;
                if(cnt2>n/2)
                {
                    cnt2--;
                    ans-=x[i].d;
                }
            }
            else if(t1==x[i].c)
            {
                cnt3++;
                if(cnt3>n/2)
                {
                    cnt3--;
                    ans-=x[i].d;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
