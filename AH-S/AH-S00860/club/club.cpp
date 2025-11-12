#include<bits/stdc++.h>
using namespace std;
long long n,T,p[4],ans;
struct in
{
    long long x,y,z,p,w;
}a[100005];
bool cnm(in u,in v)
{
    return u.p>v.p;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            long long x=a[i].x,y=a[i].y,z=a[i].z,w;
            long long q=max(x,max(y,z));
            if(q==x)w=max(y,z);
            if(q==y)w=max(x,z);
            if(q==z)w=max(y,x);
            a[i].w=w;
            a[i].p=q-w;
        }
        sort(a+1,a+n+1,cnm);
        for(int i=1;i<=n;i++)
        {
            long long ma=0,d;
            if(a[i].x>ma){ma=a[i].x;d=1;}
            if(a[i].y>ma){ma=a[i].y;d=2;}
            if(a[i].z>ma){ma=a[i].z;d=3;}
            if(ma==a[i].w)
            {
                if(min(a[i].x,min(a[i].y,a[i].z))==ma)
                {
                    if(p[1]<p[2]&&p[1]<p[3])p[1]++;
                    if(p[2]<p[1]&&p[2]<p[3])p[2]++;
                    if(p[3]<p[1]&&p[3]<p[2])p[3]++;
                    ans+=ma;
                }
                else
                {
                    if(d==1)
                    {
                        if(a[i].y>a[i].z)
                        {
                            if(p[1]<p[2])p[1]++;
                            else p[2]++;
                        }
                        else
                        {
                            if(p[1]<p[3])p[1]++;
                            else p[3]++;
                        }
                    }
                    if(d==2)
                    {
                        if(a[i].x>a[i].z)
                        {
                            if(p[1]<p[2])p[1]++;
                            else p[2]++;
                        }
                        else
                        {
                            if(p[2]<p[3])p[2]++;
                            else p[3]++;
                        }
                    }
                    if(d==3)
                    {
                        if(a[i].y>a[i].x)
                        {
                            if(p[3]<p[2])p[3]++;
                            else p[2]++;
                        }
                        else
                        {
                            if(p[1]<p[3])p[1]++;
                            else p[3]++;
                        }
                    }
                    ans+=ma;
                }
            }
            else if(p[d]==n/2)
            {
                if(d==1)
                {
                    if(a[i].y==a[i].z)
                    {
                        if(p[2]<p[3])p[2]++;
                        else p[3]++;
                    }
                    else
                    {
                        if(a[i].y>a[i].z)p[2]++;
                        else p[3]++;
                    }
                }
                if(d==2)
                {
                    if(a[i].x==a[i].z)
                    {
                        if(p[1]<p[3])p[1]++;
                        else p[3]++;
                    }
                    else
                    {
                        if(a[i].x>a[i].z)p[1]++;
                        else p[3]++;
                    }
                }
                if(d==3)
                {
                    if(a[i].y==a[i].x)
                    {
                        if(p[2]<p[1])p[2]++;
                        else p[1]++;
                    }
                    else
                    {
                        if(a[i].y>a[i].x)p[2]++;
                        else p[1]++;
                    }
                }
                ans+=a[i].w;
            }
            else
            {
                p[d]++;
                ans+=(a[i].p+a[i].w);
            }
        }
        cout<<ans<<"\n";
        ans=0;
        p[1]=p[2]=p[3]=0;
    }
    return 0;
}
