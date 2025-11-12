#include <bits/stdc++.h>
using namespace std;
int t,n,sum1,sum2,sum3,ans;
struct XS
{
    int x,y,z,b;
}a[100005];
bool cmp(XS o,XS p)
{
    if(o.b==p.b)
    {
        if(o.b==1)
            return o.x>p.x;
        if(o.b==2)
            return o.y>p.y;
        return o.z>p.z;
    }
    return o.b<p.b;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    while(t--)
    {
        cin >>n;
        sum1=0;
        sum2=0;
        sum3=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            cin >>a[i].x>>a[i].y>>a[i].z;
            if((a[i].x>a[i].y)&&(a[i].x>a[i].z))
            {
                sum1++;
                a[i].b=1;
            }
            else if((a[i].z<a[i].y)&&(a[i].y>a[i].z))
            {
                sum2++;
                a[i].b=2;
            }
            else
            {
                sum3++;
                a[i].b=3;
            }
        }
        if((sum1<=n/2)&&((sum2<=n/2)&&(sum3<=n/2)))
        {
            for(int i=1;i<=n;i++)
                ans+=max(a[i].x,max(a[i].y,a[i].z));
            cout <<ans<<endl;
            continue;
        }
        sort(a+1,a+n+1,cmp);
        if(sum1>n/2)
        {
            for(int i=n/2+1;i<=sum1;i++)
            {
                if(a[i].y>a[i].z)
                {
                    a[i].b=2;
                    sum2++;
                }
                else
                {
                    a[i].b=3;
                    sum3++;
                }
            }
        }
        else if(sum2>n/2)
        {
            for(int i=sum1+n/2+1;i<=sum1+sum2;i++)
            {
                if(a[i].x>a[i].z)
                {
                    a[i].b=1;
                    sum1++;
                }
                else
                {
                    a[i].b=3;
                    sum3++;
                }
            }
        }
        else
        {
            for(int i=sum1+sum2;i<=n;i++)
            {
                if(a[i].y>a[i].x){
                    a[i].b=2;
                    sum2++;
                }
                else
                {
                    a[i].b=1;
                    sum1++;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(a[i].b==1)
                ans+=a[i].x;
            else if(a[i].b==2)
                ans+=a[i].y;
            else
                ans+=a[i].z;
        }
        cout <<ans<<endl;
    }
    return 0;
}
