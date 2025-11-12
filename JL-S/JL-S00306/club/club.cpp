#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
}v[100005];
int mid(int x,int y,int z)
{
    int mx=max({x,y,z});
    int mn=min({x,y,z});
    if(x!=mx&&x!=mn)
    {
        return x;
    }
    if(y!=mx&&y!=mn)
    {
        return y;
    }
    if(z!=mx&&z!=mn)
    {
        return z;
    }
    if(x==y)return x;
    if(x==z)return x;
    if(y==z)return y;
}
int ans=0;
int tg[100005];
bool cmp(node a,node b)
{
    if((max({a.a,a.b,a.c})-mid(a.a,a.b,a.c))==(max({b.a,b.b,b.c})-mid(b.a,b.b,b.c)))return max({a.a,a.b,a.c})>max({b.a,b.b,b.c});
    return (max({a.a,a.b,a.c})-mid(a.a,a.b,a.c))>(max({b.a,b.b,b.c})-mid(b.a,b.b,b.c));
}
int main()
{
    freopen("club5.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    int cc=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(tg,0,sizeof(tg));
        memset(v,0,sizeof(v));
        ans=0;
        int m1=0,m2=0,m3=0;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            /*
            int mx=max({x,y,z});
            if(x==mx&&y==mx&&z==mx)
            {
                ans+=mx;
                tg[i]=1;
            }
            if((x==mx&&y==mx)||(x==mx&&z==mx)||(y==mx&&z==mx))
            {
                ans+=mx;
                tg[i]=1;
            }
            */
            v[i]={x,y,z};
        }
        sort(v+1,v+n+1,cmp);
        for(int i=1;i<=n;i++)
        {
//            if(tg[i])continue;
            int mx=max({v[i].a,v[i].b,v[i].c});
            int md=mid(v[i].a,v[i].b,v[i].c);
            int x=v[i].a,y=v[i].b,z=v[i].c;
            if(z==0)
            {
                mx=max(x,y);
                md=min(x,y);
            }
            if(y==0)
            {
                mx=max(x,z);
                md=min(x,z);
            }
            if(x==0)
            {
                mx=max(y,z);
                md=min(y,z);
            }
            if(x==mx)
            {
                if(m1==n/2)
                {
                    ans+=md;
                }
                else
                {
                    ans+=x;
                    m1++;
                }
            }
            else if(y==mx)
            {
                if(m2==n/2)
                {
                    ans+=md;
                }
                else
                {
                    ans+=y;
                    m2++;
                }
            }
            else if(z==mx)
            {
                if(m3==n/2)
                {
                    ans+=md;
                }
                else
                {
                    ans+=z;
                    m3++;
                }
            }
        }
        printf("%d\n",ans);
        /*
        for(int i=1;i<=n/2;i++)
        {
            if(tg[i])continue;
            int mx=max({v[i].a,v[i].b,v[i].c});
            ans+=mx;
            if(v[i].a==mx)q1.push({mx-mid(v[i].a,v[i].b,v[i].c),i});
            if(v[i].b==mx)q2.push({mx-mid(v[i].a,v[i].b,v[i].c),i});
            if(v[i].c==mx)q3.push({mx-mid(v[i].a,v[i].b,v[i].c),i});
        }
        */
        /*
        for(int i=n/2+1;i<=n;i++)
        {
            if(tg[i])continue;
            int mx=max({v[i].a,v[i].b,v[i].c});
            int md=mid(v[i].a,v[i].b,v[i].c)
            if(v[i].a==mx)
            {
                if(q1.size()==n/2)
                {
                    edge top=q1.top();
                    q1.pop();
                    int cha=mx-md;
                    if(cha>top.val)
                    {
                        q1.push(cha);
                        ans+=v[i].a;
                        ans-=v[top.id].                    }
                    else
                    {
                        if(v[i].b==md)q2.push(v[i].a-v[i].b);
                        else q3.push(v[i].a-v[i].c);
                    }
                }
            }
        }
        */

    }
}
