#include<bits/stdc++.h>
using namespace std;
int a[102];
int n,m,k;
void dfs(int x,int y,int t,int st)
{
    if(a[st]==k)
    {
        printf("%d %d",x,y);
        exit(0);
    }
    int xx=x,yy=y+t;
    if(yy>n||yy<1)
    {
        yy=y;
        xx++;
        t=-1*t;
    }
    dfs(xx,yy,t,st+1);
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++)
    {
        scanf("%d",&a[i]);
    }
    k=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=i+1;j<=n*m;j++)
        {
            if(a[j]>a[i]) swap(a[i],a[j]);
        }
    }
    dfs(1,1,1,1);
    return 0;
}
