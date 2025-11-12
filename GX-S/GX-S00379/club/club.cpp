#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int T;
int n;
struct stu
{
    int a,b,c;
    int maxn,maxnid;
    friend bool operator < (const stu &x,const stu &y)
    {
        return x.maxn>y.maxn;
    }
}s[N];
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
            scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
            if(s[i].a>s[i].b)
            {
                if(s[i].a>s[i].c) s[i].maxn=s[i].a,s[i].maxnid=1;
                else s[i].maxn=s[i].c,s[i].maxnid=3;
            }
            else
            {
                if(s[i].b>s[i].c) s[i].maxn=s[i].b,s[i].maxnid=2;
                else s[i].maxn=s[i].c,s[i].maxnid=3;
            }
        }
        ll ans=0,ans2=0;
        int mid=n/2;
        int cnta=0,cntb=0,cntc=0;
        sort(s+1,s+1+n);
        for(int i=1;i<=n;i++)
        {
            if(s[i].maxnid==1)
            {
                if(cnta<mid)
                    cnta++,ans+=s[i].maxn;
                else
                {
                    if(s[i].b>s[i].c)
                        cntb++,ans+=s[i].b;
                    else cntc++,ans+=s[i].c;
                }
            }
            else if(s[i].maxnid==2)
            {
                if(cntb<mid)
                    cntb++,ans+=s[i].maxn;
                else
                {
                    if(s[i].a>s[i].c)
                        cnta++,ans+=s[i].a;
                    else cntc++,ans+=s[i].c;
                }
            }
            else
            {
                if(cntc<mid)
                    cntc++,ans+=s[i].maxn;
                else
                {
                    if(s[i].a>s[i].b)
                        cnta++,ans+=s[i].a;
                    else cntb++,ans+=s[i].b;
                }
            }
        }
        cnta=0,cntb=0,cntc=0;
        for(int i=n;i>=1;i--)
        {
            if(s[i].maxnid==1)
            {
                if(cnta<mid)
                    cnta++,ans2+=s[i].maxn;
                else
                {
                    if(s[i].b>s[i].c)
                        cntb++,ans2+=s[i].b;
                    else cntc++,ans2+=s[i].c;
                }
            }
            else if(s[i].maxnid==2)
            {
                if(cntb<mid)
                    cntb++,ans2+=s[i].maxn;
                else
                {
                    if(s[i].a>s[i].c)
                        cnta++,ans2+=s[i].a;
                    else cntc++,ans2+=s[i].c;
                }
            }
            else
            {
                if(cntc<mid)
                    cntc++,ans2+=s[i].maxn;
                else
                {
                    if(s[i].a>s[i].b)
                        cnta++,ans2+=s[i].a;
                    else cntb++,ans2+=s[i].b;
                }
            }
        }
        printf("%lld\n",max(ans,ans2));
    }
    return 0;
}
