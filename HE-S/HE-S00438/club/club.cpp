#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct jade
{
    int a,b,c;
}r[100010];
struct seek
{
    int id,x;
}th1[100010],th2[100010],th3[100010],px[5];
bool cmp(seek x,seek y)
{
    return x.x<y.x;
}
int as,bs,cs;
int main()
{
    ios::sync_with_stdio(false);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        ans=0;
        as=0;
        bs=0;
        cs=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>r[i].a>>r[i].b>>r[i].c;
            px[1].id=1;
            px[1].x=r[i].a;
            px[2].id=2;
            px[2].x=r[i].b;
            px[3].id=3;
            px[3].x=r[i].c;
            sort(px+1,px+1+3,cmp);
            ans+=px[3].x;
            if(px[3].id==1)
            {
                as++;
                th1[as].id=i;
                th1[as].x=px[3].x-px[2].x;
            }
            else if(px[3].id==2)
            {
                bs++;
                th2[bs].id=i;
                th2[bs].x=px[3].x-px[2].x;
            }
            else
            {
                cs++;
                th3[cs].id=i;
                th3[cs].x=px[3].x-px[2].x;
            }
        }
        if(as>n/2)
        {
            sort(th1+1,th1+as+1,cmp);
            int js=as-n/2;
            for(int i=1;i<=js;i++)
            {
                ans-=th1[i].x;
            }
        }
        if(bs>n/2)
        {
            sort(th2+1,th2+bs+1,cmp);
            int js=bs-n/2;
            for(int i=1;i<=js;i++)
            {
                ans-=th2[i].x;
            }
        }
        if(cs>n/2)
        {
            sort(th3+1,th3+cs+1,cmp);
            int js=cs-n/2;
            for(int i=1;i<=js;i++)
            {
                ans-=th3[i].x;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

