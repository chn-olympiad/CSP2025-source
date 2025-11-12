#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x,xt,y,yt;
}a[100005];
int t,n,f[5],ans;
bool cmp(node x,node y)
{
    return x.x+y.y>x.y+y.x;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        int x1,x2,x3;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x1,&x2,&x3);
            if (x1>=x2)
            {
                if (x2>=x3)
                {
                    a[i].x=x1;a[i].xt=1;a[i].y=x2;a[i].yt=2;
                }
                else
                {
                    if (x1>=x3)
                    {
                        a[i].x=x1;a[i].xt=1;a[i].y=x3;a[i].yt=3;
                    }
                    else
                    {
                        a[i].x=x3;a[i].xt=3;a[i].y=x1;a[i].yt=1;
                    }
                }
            }
            else
            {
                if (x1>=x3)
                {
                    a[i].x=x2;a[i].xt=2;a[i].y=x1;a[i].yt=1;
                }
                else
                {
                    if (x2>=x3)
                    {
                        a[i].x=x2;a[i].xt=2;a[i].y=x3;a[i].yt=3;
                    }
                    else
                    {
                        a[i].x=x3;a[i].xt=3;a[i].y=x2;a[i].yt=2;
                    }
                }
            }
        }
        sort(a+1,a+n+1,cmp);
        ans=0;f[1]=0;f[2]=0;f[3]=0;
        for (int i=1;i<=n;i++)
        {
            if (f[a[i].xt]<n/2)
            {
                ans+=a[i].x;
                f[a[i].xt]++;
            }
            else
            {
                ans+=a[i].y;
                f[a[i].yt]++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
