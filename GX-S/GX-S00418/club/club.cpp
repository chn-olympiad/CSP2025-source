#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll cnt,n,t,tp[4];
struct player
{
    ll x=0,y=0,z=0,mxcnt=1,scmxcnt=2,mx=0,scmx=0;
}a[100005];
bool cmp(player a,player b)
{
    if(a.mx-a.scmx<b.mx-b.scmx)return true;
    return false;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(ll i=1;i<=t;++i)
    {
        cnt=0;
        for(ll j=1;j<=3;++j)tp[j]=0;
        cin>>n;
        for(ll j=1;j<=n;++j)
        {
            cin>>a[j].x>>a[j].y>>a[j].z;
            if(a[j].x>=a[j].y&&a[j].x>=a[j].z)
            {
                a[j].mxcnt=1,a[j].mx=a[j].x;
                if(a[j].y>=a[j].z)a[j].scmxcnt=2,a[j].scmx=a[j].y;
                else a[j].scmxcnt=3,a[j].scmx=a[j].z;
            }
            else if(a[j].y>=a[j].x&&a[j].y>=a[j].z)
            {
                a[j].mxcnt=2,a[j].mx=a[j].y;
                if(a[j].x>=a[j].z)a[j].scmxcnt=1,a[j].scmx=a[j].x;
                else a[j].scmxcnt=3,a[j].scmx=a[j].z;
            }
            else
            {
                a[j].mxcnt=3,a[j].mx=a[j].z;
                if(a[j].x>=a[j].y)a[j].scmxcnt=1,a[j].scmx=a[j].x;
                else a[j].scmxcnt=2,a[j].scmx=a[j].y;
            }
            cnt+=a[j].mx;
            ++tp[a[j].mxcnt];
        }
        sort(a+1,a+n+1,cmp);
        for(ll j=1;j<=3;++j)for(ll k=1;tp[j]>n/2&&k<=n;++k)if(a[k].mxcnt==j)
        {
                cnt=cnt-a[k].mx+a[k].scmx;
                --tp[j];
        }
        cout<<cnt<<'\n';
    }
    return 0;
}
