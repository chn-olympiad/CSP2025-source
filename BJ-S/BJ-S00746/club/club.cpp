#include<iostream>
#include<algorithm>
using namespace std;
int xqdr[5],ans,zxq=-1;
struct node
{
    int x,y;
};
bool cmp1(node x,node y)
{
    return x.x<y.x;
}
struct pp
{
    node x[5];
    void xqn()
    {
        x[1].y=1;
        x[2].y=2;
        x[3].y=3;
        sort(x+1,x+3+1,cmp1);
        if(x[2].x!=x[3].x)
        {
            xqdr[x[3].y]+=1;
        }
        else
        {
            ans+=x[3].x;
            x[3].x=x[2].x=x[1].x=-1;
        }
    }
};
pp a[100005];
bool cmp2(pp x,pp y)
{
    int xx,yx;
    if(x.x[3].x==-1||x.x[3].y!=zxq)return false;
    if(y.x[3].x==-1||y.x[3].y!=zxq)return true;
    for(int i=1;i<=3;i++)
    {
        if(x.x[i].y==zxq)
        {
            xx=x.x[i].x;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if(y.x[i].y==zxq)
        {
            yx=y.x[i].x;
        }
    }
    if(y.x[2].x+xx>yx+x.x[2].x)
    {
        return true;
    }
    return false;
}
void run()
{
    ans=0;
    for(int i=1;i<=3;i++)
    {
        xqdr[i]=0;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x[1].x>>a[i].x[2].x>>a[i].x[3].x;
        a[i].xqn();
    }
    zxq=-1;
    for(int i=1;i<=3;i++)
    {
        if(xqdr[i]>n/2)
        {
            zxq=i;
            break;
        }
    }
    int i=1;
    if(zxq!=-1)
    {
        sort(a+1,a+n+1,cmp2);
        for(i=1;i<=n/2;i++)
        {
            ans+=a[i].x[3].x;
        }
    }
    for(;i<=n;i++)
    {
        if(a[i].x[3].x!=-1)
        {
            if(a[i].x[3].y!=zxq)
            {
                ans+=a[i].x[3].x;
            }
            else
            {
                ans+=a[i].x[2].x;
            }
        }
    }
    cout<<ans<<endl;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        run();
    }
    return 0;
}