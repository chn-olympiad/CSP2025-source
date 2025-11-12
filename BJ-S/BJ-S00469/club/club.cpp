#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,ans1=0;
struct node
{
    int a,b,c;
}a[100005],x[100005],y[100005],z[100005];
int vis[100005];
bool cmp1(node x,node y)
{
    if(x.a!=y.a)return x.a>y.a;
    if(x.b!=y.b)return x.b>y.b;
    return x.c>y.c;
}
bool cmp2(node x,node y)
{
    return x.a-x.b>=y.a-y.b;
}
void dfs(int step)
{
    if(step==n)
    {
        int i,sum=0,cnt1=0,cnt2=0,cnt3=0;
        for(i=1;i<=n;++i)
        {
            if(vis[i]==0)cnt1++;
            if(vis[i]==1)cnt2++;
            if(vis[i]==2)cnt3++;
        }
        if(cnt1>n/2 || cnt2>n/2 || cnt3>n/2)
            return;
        for(i=1;i<=n;++i)
        {
            if(vis[i]==0)sum+=a[i].a;
            if(vis[i]==1)sum+=a[i].b;
            if(vis[i]==2)sum+=a[i].c;
        }
        ans1=max(ans1,sum);
        return;
    }
    for(int i=0;i<3;++i)
    {
        vis[step+1]=i;
        dfs(step+1);
    }
    //vis[step+1]=0;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        int i,cnt1=0,cnt2=0,cnt3=0,ans=0,max0=0,max1=0,max2=0;
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>a[i].a>>a[i].b>>a[i].c;
            max0=max(max0,a[i].a),max1=max(max1,a[i].b),max2=max(max2,a[i].c);
            if(a[i].a>=a[i].b && a[i].a>=a[i].c)
                cnt1++,x[cnt1].a=a[i].a,x[cnt1].b=a[i].b,x[cnt1].c=a[i].c;
            if(a[i].b>=a[i].a && a[i].b>=a[i].c)
                cnt2++,y[cnt2].a=a[i].a,y[cnt2].b=a[i].b,y[cnt2].c=a[i].c;
            if(a[i].c>=a[i].b && a[i].c>=a[i].a)
                cnt3++,z[cnt3].a=a[i].a,z[cnt3].b=a[i].b,z[cnt3].c=a[i].c;
        }
        if(cnt1<=n/2 && cnt2<=n/2 && cnt3<=n/2)
        {
            for(i=1;i<=cnt1;++i)ans+=x[i].a;
            for(i=1;i<=cnt2;++i)ans+=y[i].b;
            for(i=1;i<=cnt3;++i)ans+=z[i].c;
            cout<<ans<<endl;
            continue;
        }
        if(max1==0 && max2==0 && max0)
        {
            sort(a+1,a+1+n,cmp2);
            for(i=1;i<=n/2;++i)
                ans+=a[i].a;
            cout<<ans<<endl;
            continue;
        }
        if(max2==0 && max0)
        {
            sort(a+1,a+1+n,cmp2);
            for(i=1;i<=n/2;++i)
                ans+=a[i].a;
            for(i=n/2+1;i<=n;++i)
                ans+=a[i].b;
            cout<<ans<<endl;
            continue;
        }//*/
        ans1=0;
        dfs(0);
        cout<<ans1<<endl;
        /*else if(cnt1>n/2)
        {
            sort(x+1,x+1+cnt1,cmp1);
            for(i=1;i<=cnt1-n/2;++i)
            {


            }
        }*/

    }
    return 0;
}
