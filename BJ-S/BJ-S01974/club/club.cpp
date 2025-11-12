#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,t;
struct Node
{
    long long fi,se,th;
} a[N];
bool cmp(Node &x,Node &y)
{
    return x.fi>y.fi;
}
long long ans;
void baoli(long long nw,long long sum,long long ge1,long long ge2,long long ge3)
{
    if(nw==n)
    {
        ans=max(ans,sum);
        return ;
    }
    if(ge1<n/2) baoli(nw+1,sum+a[nw+1].fi,ge1+1,ge2,ge3);
    if(ge2<n/2) baoli(nw+1,sum+a[nw+1].se,ge1,ge2+1,ge3);
    if(ge3<n/2) baoli(nw+1,sum+a[nw+1].th,ge1,ge2,ge3+1);
}
long long vit[N];
struct No
{
    long long u,val,bi;
    bool operator <(const No &tmp) const
    {
        return val>tmp.val;
    }
} b[N];
long long cnt;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        memset(vit,0,sizeof(vit));
        ans=0;
        cin>>n;
        long long fl=0;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i].fi>>a[i].se>>a[i].th;
            if(a[i].se!=0 || a[i].th!=0) fl=1;
        }
        if(!fl)
        {
            sort(a+1,a+n+1,cmp);
            long long ans=0;
            for(long long i=1;i<=n/2;i++) ans+=a[i].fi;
            cout<<ans<<"\n";
            continue;
        }
        if(n<=20)
        {
            baoli(0,0,0,0,0);
            cout<<ans<<"\n";
            continue;
        }
        long long tan=0,gef=0,ges=0,get=0;
        for(long long i=1;i<=n;i++)
        {
            if(a[i].fi>=a[i].se && a[i].fi>=a[i].th)
            {
                tan+=a[i].fi;
                gef++;
                vit[i]=1;
            }
            if(a[i].se>=a[i].fi && a[i].se>=a[i].th && !vit[i]) tan+=a[i].se,ges++,vit[i]=2;
            if(a[i].th>=a[i].fi && a[i].th>=a[i].se && !vit[i]) tan+=a[i].th,get++,vit[i]=3;
        }
        if(gef>n/2)
        {
            cnt=0;
            for(long long i=1;i<=n;i++)
            {
                if(vit[i]==1)
                {
                    b[++cnt].u=i;
                    if(a[i].se-a[i].fi>=a[i].th-a[i].fi) b[cnt].val=a[i].se-a[i].fi,b[cnt].bi=2;
                    else b[cnt].val=a[i].th-a[i].fi,b[cnt].bi=3;
                }
            }
            sort(b+1,b+cnt+1);
            long long ff=0;
            while(gef>n/2)
            {
                gef--,tan+=b[ff+1].val;
                if(b[ff+1].bi==2) ges++,vit[b[ff+1].u]=2;
                else get++,vit[b[ff+1].u]=3;
                ff++;
            }
        }
        for(long long i=1;i<=cnt;i++) b[i].u=0,b[i].val=0,b[i].bi=0;
        if(ges>n/2)
        {
            cnt=0;
            for(long long i=1;i<=n;i++)
            {
                if(vit[i]==2)
                {
                    b[++cnt].u=i;
                    if(a[i].fi-a[i].se>=a[i].th-a[i].se) b[cnt].val=a[i].fi-a[i].se,b[cnt].bi=1;
                    else b[cnt].val=a[i].th-a[i].se,b[cnt].bi=3;
                }
            }
            sort(b+1,b+cnt+1);
            long long ff=0;
            while(ges>n/2)
            {
                ges--,tan+=b[ff+1].val;
                if(b[ff+1].bi==1) gef++,vit[b[ff+1].u]=1;
                else get++,vit[b[ff+1].u]=3;
            }
        }
        for(long long i=1;i<=cnt;i++) b[i].u=0,b[i].val=0,b[i].bi=0;
        if(get>n/2)
        {
            cnt=0;
            for(long long i=1;i<=n;i++)
            {
                if(vit[i]==3)
                {
                    b[++cnt].u=i;
                    if(a[i].fi-a[i].th>=a[i].se-a[i].th) b[cnt].val=a[i].fi-a[i].th,b[cnt].bi=1;
                    else b[cnt].val=a[i].se-a[i].th,b[cnt].bi=2;
                }
            }
            sort(b+1,b+cnt+1);
            long long ff=0;
            while(get>n/2)
            {
                get--,tan+=b[ff+1].val;
                if(b[ff+1].bi==1) gef++,vit[b[ff+1].u]=1;
                else ges++,vit[b[ff+1].u]=2;
            }
        }
        for(long long i=1;i<=cnt;i++) b[i].u=0,b[i].val=0,b[i].bi=0;
        if(gef>n/2)
        {
            cnt=0;
            for(long long i=1;i<=n;i++)
            {
                if(vit[i]==1)
                {
                    b[++cnt].u=i;
                    if(a[i].se-a[i].fi>=a[i].th-a[i].fi) b[cnt].val=a[i].se-a[i].fi,b[cnt].bi=2;
                    else b[cnt].val=a[i].th-a[i].fi,b[cnt].bi=3;
                }
            }
            sort(b+1,b+cnt+1);
            long long ff=0;
            while(gef>n/2)
            {
                gef--,tan+=b[ff+1].val;
                if(b[ff+1].bi==2) ges++,vit[b[ff+1].u]=2;
                else get++,vit[b[ff+1].u]=3;
                ff++;
            }
        }
        for(long long i=1;i<=cnt;i++) b[i].u=0,b[i].val=0,b[i].bi=0;
        cout<<tan<<"\n";
    }
    return 0;
}
