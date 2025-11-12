#include<bits/stdc++.h>
using namespace std;
long long a[114514],b[114514],c[114514],s,max[114514];
long long n,d,e,f,m;
int t;
bool v;
int sch()
{
    s=0;
    d=0;
    e=0;
    f=0;
    v=true;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i]>>c[i];
        if(a[i]>b[i]&&a[i]>c[i])
        {
            b[i]=0;
            c[i]=0;
            d++;
            s+=a[i];
        }
        if(b[i]>a[i]&&b[i]>c[i])
        {
            a[i]=0;
            c[i]=0;
            e++;
            s+=b[i];
        }
        if(c[i]>a[i]&&c[i]>b[i])
        {
            a[i]=0;
            b[i]=0;
            f++;
            s+=c[i];
        }
    }
    if(d>n/2)
        v=false;
    if(e>n/2)
        v=false;
    if(f>n/2)
        v=false;
    if(v)
        return s;
    for(int i=2;i<=n;i++)
    {

        if(d<=n/2)
            break;
        for(int l=1;l<=n;l++)
            if(a[l]!=0)
                m=a[l];
        if(a[i]<m&&a[i]!=0)
            m=a[i];
        for(int y=1;y<=n;y++)
            if(m==a[y])
            {
                s-=a[y];
                a[y]=0;
            }
        d--;
    }
    for(int i=2;i<=n;i++)
    {
        if(e<=n/2)
            break;
        for(int l=1;l<=n;l++)
            if(b[l]!=0)
                m=b[l];
        if(b[i]<m&&b[i]!=0)
            m=b[i];
        for(int y=1;y<=n;y++)
            if(m==b[y])
            {
                s-=b[y];
                b[y]=0;
            }
        e--;
    }
    for(int i=2;i<=n;i++)
    {
        if(f<=n/2)
            break;
        for(int l=1;l<=n;l++)
            if(c[l]!=0)
                m=c[l];
        if(c[i]<m&&c[i]!=0)
            m=c[i];
        for(int y=1;y<=n;y++)
            if(m==c[y])
            {
                s-=c[y];
                c[y]=0;
            }
        f--;
    }
    return s;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int w=1;w<=t;w++)
        cout<<sch()<<endl;
    return 0;
}
