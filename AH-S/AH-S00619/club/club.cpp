#include<bits/stdc++.h>
using namespace std;
struct node
{
    int x,y,z,w;
} a[100005];
int cmp(node a,node b)
{
    return a.w<b.w;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        int sx=0,sy=0,sz=0,mx=0,ans=0;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>a[i].x>>a[i].y>>a[i].z;
            mx=max(a[i].x,max(a[i].y,a[i].z));
            if(mx==a[i].x)sx++;
            else if(mx==a[i].y)sy++;
            else sz++;
        }
        for(int i=1; i<=n; i++)
        {
            ans+=max(a[i].x,max(a[i].y,a[i].z));
        }
        if(sx<=n/2&&sy<=n/2&&sz<=n/2)
        {
            cout<<ans<<endl;
            continue;
        }
        if(sx>n/2)
        {
            for(int i=1; i<=n; i++)
            {
                a[i].w=min(a[i].x-a[i].y,a[i].x-a[i].z);
            }
            sort(a+1,a+n+1,cmp);
            int fi=1;
            while(a[fi].w<0&&fi<=n)
            {
                fi++;
            }
            for(int i=fi; i<fi+(sx-(n/2))&&i<=n; i++)
            {
                if(a[i].x-a[i].y<a[i].x-a[i].z)
                {
                    if(sy<n/2)
                    {
                        sy++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sz++;
                        ans-=a[i].x-a[i].z;
                    }
                }
                else if(a[i].x-a[i].y>a[i].x-a[i].z)
                {
                    if(sz<n/2)
                    {
                        sz++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sy++;
                        ans-=a[i].x-a[i].y;
                    }
                }
                else
                {
                    if(sy<=sz)
                    {
                        sy++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sz++;
                        ans-=a[i].w;
                    }
                }
            }
        }
        if(sy>n/2)
        {
            for(int i=1; i<=n; i++)
            {
                a[i].w=min(a[i].y-a[i].x,a[i].y-a[i].z);
            }
            sort(a+1,a+n+1,cmp);
            int fi=1;
            while(a[fi].w<0&&fi<=n)
            {
                fi++;
            }
            for(int i=fi; i<fi+(sy-(n/2))&&i<=n; i++)
            {
                if(a[i].y-a[i].x<a[i].y-a[i].z)
                {
                    if(sx<n/2)
                    {
                        sx++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sz++;
                        ans-=a[i].y-a[i].z;
                    }
                }
                else if(a[i].y-a[i].x>a[i].y-a[i].z)
                {
                    if(sz<n/2)
                    {
                        sz++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sx++;
                        ans-=a[i].y-a[i].x;
                    }
                }
                else
                {
                    if(sx<=sz)
                    {
                        sx++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sz++;
                        ans-=a[i].w;
                    }
                }
            }
        }
        if(sz>n/2)
        {
            for(int i=1; i<=n; i++)
            {
                a[i].w=min(a[i].z-a[i].y,a[i].z-a[i].x);
            }
            sort(a+1,a+n+1,cmp);
            int fi=1;
            while(a[fi].w<0&&fi<=n)
            {
                fi++;
            }
            for(int i=fi; i<fi+(sz-(n/2))&&i<=n; i++)
            {
                if(a[i].z-a[i].y<a[i].z-a[i].x)
                {
                    if(sy<n/2)
                    {
                        sy++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sx++;
                        ans-=a[i].z-a[i].x;
                    }
                }
                else if(a[i].z-a[i].y>a[i].z-a[i].x)
                {
                    if(sx<n/2)
                    {
                        sx++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sy++;
                        ans-=a[i].z-a[i].y;
                    }
                }
                else
                {
                    if(sy<=sx)
                    {
                        sy++;
                        ans-=a[i].w;
                    }
                    else
                    {
                        sx++;
                        ans-=a[i].w;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
