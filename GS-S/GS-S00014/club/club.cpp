#include<bits/stdc++.h>
using namespace std;

int t,n,d[100005],e[100005],o[100005],cnt,ans,sum,x1,x,x2,x3,x4,x5,x6,x7,x8,x9;
struct node
{
    int a,b,c,id,id1;
}s[100005];
bool cmp(node a,node b)
{
    return a.a>a.b;

}
bool cmp2(node a,node b)
{
    return b.a>b.b;
}
bool f[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    for(int i=1;i<=100005;i++)
    {
        f[i]=true;
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==2)
        {
            for(int i=1;i<=n;i++)
            {
                cin>>s[i].a>>s[i].b>>s[i].c;
                d[i]=s[i].a;
                e[i]=s[i].b;

                s[i].id=i;
            }
            x=s[1].a+s[2].b;
            x1=s[1].a+s[2].c;
            x2=s[1].b+s[2].a;
            x3=s[1].b+s[2].c;
            x4=s[1].c+s[2].a;
            x5=s[1].c+s[2].b;
            cout<<max(max(max(x,x1),max(x2,x3)),max(x4,x5));
            continue;
        }

            for(int i=1;i<=n;i++)
            {
                cin>>s[i].a>>s[i].b>>s[i].c;
                d[i]=s[i].a;
                e[i]=s[i].b;
                f[i]=s[i].c;
                s[s[i].a].id=i;
                s[s[i].b].id1=i;
            }
            if(s[1].b==s[1].c&&s[1].b==0)
            {
                sort(s+1,s+n+1,cmp);
                for(int i=1;i<=n/2;i++)
                {
                    x+=s[i].a;
                }
                cout<<x;
                continue;
            }
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n/2;i++)
        {
            x+=s[i].a;
            f[s[s[i].a].id]=false;

        }
        for(int i=1;i<=n;i++)
        {
            if(f[s[s[i].a].id])
            {
                x+=s[i].b;
                f[s[s[i].b].id1]=false;
            }
        }
        sort(s+1,s+n+1,cmp2);
        for(int i=1;i<=n/2;i++)
        {
            x1+=s[i].b;
            f[s[s[i].b].id1]=true;

        }
        for(int i=1;i<=n;i++)
        {
            if(!f[s[s[i].b].id1])
            {
                x1+=s[i].a;
                f[s[s[i].a].id]=true;
            }
        }
        cout<<max(x,x1);









    }
    return 0;
}
