#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct NODEX
{
    int sx;
    int nx;
};
struct node
{
    NODEX x;
    NODEX y;
    NODEX z;
};
int t;
bool vis[100010];
node a[100010];
bool cmp(NODEX w,NODEX e)
{
    return w.sx>e.sx;
}
bool cmp2(node rt,node ty)
{
    return rt.x.sx>ty.x.sx;
}
NODEX we[3];
void paixu(node q,int yu)
{
    NODEX x1=q.x;
    NODEX y1=q.y;
    NODEX z1=q.z;
    memset(we,0,sizeof(we));
    we[1]=x1;
    we[2]=y1;
    we[3]=z1;
    sort(we+1,we+1+3,cmp);
    a[yu].x.nx=we[1].nx;
    a[yu].y.nx=we[2].nx;
    a[yu].z.nx=we[3].nx;
    a[yu].x.sx=we[1].sx;
    a[yu].y.sx=we[2].sx;
    a[yu].z.sx=we[3].sx;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(a,0,sizeof(a));
        ll zsum=n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].x.sx>>a[i].y.sx>>a[i].z.sx;
            a[i].x.nx=1;
            a[i].y.nx=2;
            a[i].z.nx=3;
        }
        ll sum1=0,sum2=0,sum3=0;
        const ll n2=n/2;
        for(int i=1;i<=n;i++)
        {
            paixu(a[i],i);
        }
        sort(a+1,a+1+n,cmp2);
        ll sum=0;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            if(a[i].x.nx==1&&sum1<n2)
            {
                sum1++;
                zsum--;
                vis[i]=1;
                sum+=a[i].x.sx;
            }
            if(a[i].x.nx==2&&sum2<n2)
            {
                sum2++;
                zsum--;
                vis[i]=1;
                sum+=a[i].x.sx;
            }
            if(a[i].x.nx==3&&sum3<n2)
            {
                sum3++;
                zsum--;
                vis[i]=1;
                sum+=a[i].x.sx;
            }
        }
        if(zsum>0)
        {
            for(int i=1;i<=n;i++)
            {
                if(zsum<=0) break;
                if(vis[i]==0)
                {
                    if(a[i].y.nx==1&&sum1<n2)
                    {
                        sum1++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].y.sx;
                    }
                    if(a[i].y.nx==2&&sum2<n2)
                    {
                        sum2++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].y.sx;
                    }
                    if(a[i].x.nx==3&&sum3<n2)
                    {
                        sum3++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].y.sx;
                    }
                }
            }
        }
        if(zsum>0)
        {
            for(int i=1;i<=n;i++)
            {
                if(zsum<=0) break;
                if(vis[i]==0)
                {
                    if(a[i].z.nx==1&&sum1<n2)
                    {
                        sum1++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].z.sx;
                    }
                    if(a[i].z.nx==2&&sum2<n2)
                    {
                        sum2++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].z.sx;
                    }
                    if(a[i].z.nx==3&&sum3<n2)
                    {
                        sum3++;
                        zsum--;
                        vis[i]=1;
                        sum+=a[i].z.sx;
                    }
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
