#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t;
int n;
struct node
{
    int x,y,z;
    int maxn,id;
}a[N];
int c[N];
bool cmp(node e,node f)
{
    return e.maxn>f.maxn;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        int ans=0,f=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z)
                a[i].maxn=a[i].x,a[i].id=1;
            else if(a[i].y>=a[i].x&&a[i].y>=a[i].z)
                a[i].maxn=a[i].y,a[i].id=2;
            else
                a[i].maxn=a[i].z,a[i].id=3;
            if(a[i].x==0&&a[i].y==0||a[i].x==0&&a[i].z==0||a[i].y==0&&a[i].z==0)
                f++;
        }
        int len1=0,len2=0,len3=0;
        int ans1=0,ans2=0,ans3=0;
        sort(a+1,a+n+1,cmp);
        if(f==n)
        {
            for(int i=1;i<=n/2;i++)
                ans+=a[i].maxn;
            cout<<ans<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].x==0&&a[i].y==0)
                c[i]=a[i].z;
            if(a[i].x==0&&a[i].z==0)
                c[i]=a[i].y;
            if(a[i].y==0&&a[i].z==0)
                c[i]=a[i].x;
        }
        int cc=0;
        for(int i=n;i>=1;i--)
        {
            if(c[i])
                cc=c[i];
            if(!c[i]&&f!=0)
            {
                f--;
                if(a[i].id==1)
                {
                    if(a[i].y>=a[i].z)
                    {
                        if(a[i].x-a[i].y<cc)
                            a[i].id=2,a[i].maxn=a[i].y,cc=0;
                    }
                    else if(a[i].x-a[i].z<cc)
                        a[i].id=3,a[i].maxn=a[i].z,cc=0;
                }
                else if(a[i].id==2)
                {
                    if(a[i].x>=a[i].z)
                    {
                        if(a[i].y-a[i].x<cc)
                            a[i].id=1,a[i].maxn=a[i].x,cc=0;
                    }
                    else if(a[i].y-a[i].z<cc)
                        a[i].id=3,a[i].maxn=a[i].z,cc=0;
                }
                else if(a[i].id==3)
                {
                    if(a[i].y>=a[i].x)
                    {
                        if(a[i].z-a[i].y<cc)
                            a[i].id=2,a[i].maxn=a[i].y,cc=0;
                    }
                    else if(a[i].z-a[i].x<c[i])
                        a[i].id=1,a[i].maxn=a[i].x,cc=0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].id==1)
            {
                if(len1<n/2)
                    len1++,ans1+=a[i].maxn;
                else
                {
                    if(a[i].y>=a[i].z&&len2<n/2)
                        len2++,ans2+=a[i].y;
                    else if(len3<n/2)
                        len3++,ans3+=a[i].z;
                }
            }
            if(a[i].id==2)
            {
                if(len2<n/2)
                    len2++,ans2+=a[i].maxn;
                else
                {
                    if(a[i].x>=a[i].z&&len1<n/2)
                        len1++,ans1+=a[i].x;
                    else if(len3<n/2)
                        len3++,ans3+=a[i].z;
                }
            }
            if(a[i].id==3)
            {
                if(len3<n/2)
                    len3++,ans3+=a[i].maxn;
                else
                {
                    if(a[i].y>=a[i].x&&len2<n/2)
                        len2++,ans2+=a[i].y;
                    else if(len1<n/2)
                        len1++,ans1+=a[i].x;
                }
            }
        }
        cout<<ans1+ans2+ans3<<'\n';
    }
    return 0;
}
