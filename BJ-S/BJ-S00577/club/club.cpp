#include<bits/stdc++.h>
using namespace std;
int n,f[5],abc,ans=0;
bool fl=0;
struct node
{
    int f[4];
    int fa,se;
}a[100005];
bool cmp(node x,node y)
{
    if(abc!=x.fa)
    {
        return false;
    }
    if(abc!=y.fa)
    {
        return true;
    }
    return x.f[x.fa]-x.f[x.se]>y.f[y.fa]-y.f[y.se];
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        abc=0;
        ans=0;
        f[1]=0;
        f[2]=0;
        f[3]=0;
        fl=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].f[1]>>a[i].f[2]>>a[i].f[3];
            if(a[i].f[1]>=a[i].f[2])
            {
                if(a[i].f[1]>=a[i].f[3])
                {
                    a[i].fa=1;
                    if(a[i].f[2]>=a[i].f[3])
                    {
                        a[i].se=2;
                    }
                    else
                    {
                        a[i].se=3;
                    }
                }
                else
                {
                    a[i].fa=3;
                    a[i].se=1;
                }
            }
            else
            {
                if(a[i].f[2]>=a[i].f[3])
                {
                    a[i].fa=2;
                    if(a[i].f[1]>=a[i].f[3])
                    {
                        a[i].se=1;
                    }
                    else
                    {
                        a[i].se=3;
                    }
                }
                else
                {
                    a[i].fa=3;
                    a[i].se=2;
                }
            }
        }//input
        for(int i=1;i<=3;i++)
        {
            if(f[i]>n/2)
            {
                fl=1;
                abc=i;
                sort(a+1,a+n+1,cmp);
                break;
            }
        }//arrange
        if(fl)
        {
            for(int i=n;i>n/2;i--)
            {
                if(a[i].fa==abc)
                {
                    ans+=a[i].f[a[i].se];
                }
                else
                {
                    ans+=a[i].f[a[i].fa];
                }
            }
            for(int i=1;i<=n/2;i++)
            {

                ans+=a[i].f[a[i].fa];
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                ans+=a[i].f[a[i].fa];
            }
        }//calculate
        cout<<ans<<endl;//output
    }
    return 0;
}
//rp++;
