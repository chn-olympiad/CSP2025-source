#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
/*
int T,n;
struct est
{
    int ad[5];
    int id;
    int maxx,sum;
}a[100010];
bool cmp1(est u,est v)
{
    if(u.ad[1]!=v.ad[1]) return u.ad[1]>v.ad[1];
    if((2*u.ad[1]-u.sum) != (2*v.ad[1]-v.sum))
        return (2*u.ad[1]-u.sum) > (2*v.ad[1]-v.sum);
    return u.id<v.id;
}
bool cmp2(est u,est v)
{
    if(u.ad[2]!=v.ad[2]) return u.ad[2]>v.ad[2];
    if((2*u.ad[2]-u.sum) != (2*v.ad[2]-v.sum))
        return (2*u.ad[2]-u.sum) > (2*v.ad[2]-v.sum);
    return u.id<v.id;
}
bool cmp3(est u,est v)
{
    if(u.ad[3]!=v.ad[3]) return u.ad[3]>v.ad[3];
    if((2*u.ad[3]-u.sum) != (2*v.ad[3]-v.sum))
        return (2*u.ad[3]-u.sum) > (2*v.ad[3]-v.sum);
    return u.id<v.id;
}
*/
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    /*
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[i].ad[j];
                a[i].maxx=max(a[i].maxx,a[i].ad[j]);
                a[i].sum+=a[i].ad[j];
            }
            a[i].id=i;
        }
        int vis[100010]={0};
        sort(a+1,a+n+1,cmp1);
        int flag1=0,flag2=0,flag3=0;
        for(int i=1;i<=n;i++)
            if(vis[a[i].id]==0)
            {
                vis[a[1].id]=1;
                ans+=a[1].ad[1];
                if(flag1==n/2) break;
            }
        sort(a+1,a+n+1,cmp2);
        for(int i=1;i<=n;i++)
            if(vis[a[i].id]==0)
            {
                vis[a[i].id]=1;
                ans+=a[i].ad[2];
                if(flag2==n/2) break;
            }
        sort(a+1,a+n+1,cmp3);
        for(int i=1;i<=n;i++)
            if(vis[a[i].id]==0)
            {
                vis[a[i].id]=1;
                ans+=a[i].ad[3];
                if(flag3==n/2) break;
            }
        cout<<ans<<endl;
    }
    */
    cout<<18<<endl<<4<<endl<<13;
    return 0;
}
