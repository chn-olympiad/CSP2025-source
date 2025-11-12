#include<bits/stdc++.h>
using namespace std;
int t;
struct book
{
    int val,id;
};
struct node
{
    book a,b,c;
    int e,w;
}g[100009];
bool cmp(node p,node q)
{
    if(p.e!=q.e)
    {
        return p.e>q.e;
    }
    else return p.w>q.w;
}
int cnt[19];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int n,ans=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            if(a<=b&&b<=c)
            {
                g[i].a.val=c;
                g[i].a.id=3;
                g[i].b.val=b;
                g[i].b.id=2;
                g[i].c.val=a;
                g[i].c.id=1;
            }
            else if(a>=b&&b>=c)
            {
                g[i].a.val=a;
                g[i].a.id=1;
                g[i].b.val=b;
                g[i].b.id=2;
                g[i].c.val=c;
                g[i].c.id=3;
            }
            else if(a<=b&&b>=c)
            {
                if(a<=c)
                {
                    g[i].a.val=b;
                    g[i].a.id=2;
                    g[i].b.val=c;
                    g[i].b.id=3;
                    g[i].c.val=a;
                    g[i].c.id=1;
                }
                else
                {
                    g[i].a.val=b;
                    g[i].a.id=2;
                    g[i].b.val=a;
                    g[i].b.id=1;
                    g[i].c.val=c;
                    g[i].c.id=3;
                }
            }
            else if(a>=b&&b<=c)
            {
                if(a<=c)
                {
                    g[i].a.val=c;
                    g[i].a.id=3;
                    g[i].b.val=a;
                    g[i].b.id=1;
                    g[i].c.val=b;
                    g[i].c.id=2;
                }
                else
                {
                    g[i].a.val=a;
                    g[i].a.id=1;
                    g[i].b.val=c;
                    g[i].b.id=3;
                    g[i].c.val=b;
                    g[i].c.id=2;
                }
            }
            g[i].e=g[i].a.val-g[i].b.val;
            g[i].w=g[i].b.val-g[i].c.val;
        }
        sort(g+1,g+n+1,cmp);


        /*for(int i=1;i<=n;i++)
        {
            cout<<g[i].a.val<<" "<<g[i].b.val<<" "<<g[i].c.val<<endl;
        }*/


        for(int i=1;i<=n;i++)
        {
            if(cnt[g[i].a.id]>=n/2)
            {
                if(cnt[g[i].b.id]>=n/2)
                {
                    cnt[g[i].c.id]++;
                    ans+=g[i].c.val;
                }
                else
                {
                    cnt[g[i].b.id]++;
                    ans+=g[i].b.val;
                }
            }
            else
            {
                cnt[g[i].a.id]++;
                ans+=g[i].a.val;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
