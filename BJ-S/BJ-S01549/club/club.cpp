#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
struct node
{
    int x,y,z,c;
    bool operator < (const node o)const
    {
        return o.c<c;
    }
}a[111111];
void solve()
{
    int q1=0,q2=0,q3=0;
    ans = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y>>a[i].z;
        if(a[i].x>=max(a[i].y,a[i].z))
        {
            a[i].c=min(a[i].x-a[i].y,a[i].x-a[i].z);
        }
        else if(a[i].y>=max(a[i].x,a[i].z))
        {
            a[i].c=min(a[i].y-a[i].x,a[i].y-a[i].z);
        }
        else if(a[i].z>=max(a[i].x,a[i].y))
        {
            a[i].c=min(a[i].z-a[i].x,a[i].z-a[i].y);
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i].x>=max(a[i].y,a[i].z))
        {
            if(q1<n/2)q1++,ans+=a[i].x;
            else
            {
                ans+=max(a[i].y,a[i].z);
            }
        }
        else if(a[i].y>=max(a[i].x,a[i].z))
        {
            if(q2<n/2)q2++,ans+=a[i].y;
            else
            {
                ans+=max(a[i].x,a[i].z);
            }
        }
        else if(a[i].z>=max(a[i].y,a[i].x))
        {
            if(q3<n/2)q3++,ans+=a[i].z;
            else
            {
                ans+=max(a[i].y,a[i].x);
            }
        }
    }
    cout<<ans<<endl;
    return ;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--) solve();
    return 0;
}
