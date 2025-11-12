#include <bits/stdc++.h>
using namespace std;
int t,n;
struct qwert
{
    int x;
    int y;
    int z;
    int num;
}a[100010];
struct trewq
{
    int maxv;
    int unm;
    int mun;
}b[100010];
bool cmpq(qwert n,qwert m)
{
    return n.x>m.x;
}
bool cmpe(qwert n,qwert m)
{
    return n.y>m.y;
}
bool cmpu(qwert n,qwert m)
{
    return n.z>m.z;
}
bool cmpw(trewq n,trewq m)
{
    return n.maxv>m.maxv;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int q=1,w=1,qw=0,e=1,r=1,u=1,o=1;
        int as=0;
        int sd=0;
        int df=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            a[i].num=i;
            if(a[i].y!=0||a[i].z!=0)
            {
                q=0;
            }
            if(a[i].z!=0)
            {
                w=0;
            }
            if(a[i].x!=0||a[i].z!=0)
            {
                e=0;
            }
            if(a[i].y!=0)
            {
                r=0;
            }
            if(a[i].x!=0||a[i].y!=0)
            {
                u=0;
            }
            if(a[i].x!=0)
            {
                o=0;
            }
            b[i].mun=i;
            b[i].maxv=max(a[i].x,max(a[i].y,a[i].z));
            if(b[i].maxv==a[i].x)
            {
                b[i].unm=1;
                as++;
            }
            else if(b[i].maxv==a[i].y)
            {
                b[i].unm=2;
                sd++;
            }
            else
            {
                b[i].unm=3;
                df++;
            }
        }
        if(q==1)
        {
            sort(a+1,a+1+n,cmpq);
            int qwe=0;
            for(int i=1;i<=n/2;i++)
            {
                qwe+=a[i].x;
            }
            cout<<qwe<<endl;
            continue;
        }
        if(w==1&&n==2)
        {
            cout<<max(a[1].x+a[2].y,a[1].y+a[2].x);
            continue;
        }
        if(e==1)
        {
            sort(a+1,a+1+n,cmpe);
            int qwe=0;
            for(int i=1;i<=n/2;i++)
            {
                qwe+=a[i].y;
            }
            cout<<qwe<<endl;
            continue;
        }
        if(r==1&&n==2)
        {
            cout<<max(a[1].x+a[2].z,a[1].z+a[2].x);
            continue;
        }
        if(u==1)
        {
            sort(a+1,a+1+n,cmpu);
            int qwe=0;
            for(int i=1;i<=n/2;i++)
            {
                qwe+=a[i].z;
            }
            cout<<qwe<<endl;
            continue;
        }
        if(o==1&&n==2)
        {
            cout<<max(a[1].y+a[2].z,a[1].z+a[2].y);
            continue;
        }
        sort(b+1,b+1+n,cmpw);
        if(as>n/2)
        {
            int j=n;
            while(as>n/2)
            {
                if(b[j].unm==1)
                {
                    as--;
                    b[j].maxv=max(a[b[j].mun].y,a[b[j].mun].z);
                    if(b[j].maxv==a[b[j].mun].y)
                    {
                        b[j].unm=2;
                        sd++;
                        if(sd>n/2)
                        {
                            b[j].maxv=a[b[j].mun].z;
                            sd--;
                            df++;
                        }
                    }
                    else
                    {
                        b[j].unm=3;
                        df++;
                        if(df>n/2)
                        {
                            b[j].maxv=a[b[j].mun].y;
                            df--;
                            sd++;
                        }
                    }
                    j--;
                }
            }
        }
        else if(sd>n/2)
        {
            int j=n;
            while(sd>n/2)
            {
                if(b[j].unm==2)
                {
                    sd--;
                    b[j].maxv=max(a[b[j].mun].x,a[b[j].mun].z);
                    if(b[j].maxv==a[b[j].mun].x)
                    {
                        b[j].unm=1;
                        as++;
                        if(as>n/2)
                        {
                            b[j].maxv=a[b[j].mun].z;
                            as--;
                            df++;
                        }
                    }
                    else
                    {
                        b[j].unm=3;
                        df++;
                        if(df>n/2)
                        {
                            b[j].maxv=a[b[j].mun].x;
                            df--;
                            as++;
                        }
                    }
                    j--;
                }
            }
        }
        else if(df>n/2)
        {
            int j=n;
            while(df>n/2)
            {
                if(b[j].unm==3)
                {
                    df--;
                    b[j].maxv=max(a[b[j].mun].x,a[b[j].mun].y);
                    if(b[j].maxv==a[b[j].mun].x)
                    {
                        b[j].unm=1;
                        as++;
                        if(as>n/2)
                        {
                            b[j].maxv=a[b[j].mun].y;
                            as--;
                            sd++;
                        }
                    }
                    else
                    {
                        b[j].unm=2;
                        sd++;
                        if(sd>n/2)
                        {
                            b[j].maxv=a[b[j].mun].x;
                            sd--;
                            as++;
                        }
                    }
                    j--;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=b[i].maxv;
        }
        cout<<ans;
    }
    return 0;
}
