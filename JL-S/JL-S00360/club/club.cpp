#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b;
    friend bool operator < (node a,node b)
    {
        return a.b>b.b;
    }
};
node f[110000];
int a[110000][3],n,ans=0,p[110000];
void dfs(int s,int x,int y,int z,int sum)
{
    if(s>n)
    {
        ans=max(ans,sum);
        //cout<<x<<' '<<y<<' '<<z<<endl;
        return ;
    }
    if(x<n/2)
    {
        dfs(s+1,x+1,y,z,sum+a[s][1]);
    }
    if(y<n/2)
    {
        dfs(s+1,x,y+1,z,sum+a[s][2]);
    }
    if(z<n/2)
    {
        dfs(s+1,x,y,z+1,sum+a[s][3]);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,fl,tmp;
    scanf("%d",&t);
    while(t--)
    {
        fl=tmp=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
            }
            if(a[i][2]!=0||a[i][3]!=0)fl=1;
            if(a[i][3]!=0)tmp=1;
            f[i].a=a[i][1];
            f[i].b=a[i][2];
        }
        if(fl==0)
        {
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                p[i]=a[i][1];
            }
            sort(p+1,p+n+1);
            for(int i=n/2+1;i<=n;i++)
            {
                ans+=p[i];
            }
            printf("%lld\n",ans);
            continue;
        }
        else if(tmp==0)
        {
            long long ans=0;
            sort(f+1,f+n+1);
            for(int i=1;i<=n;i++)
            {
                if(i<=n/2)
                {
                    ans+=f[i].b;
                }
                else
                {
                    ans+=f[i].a;
                }
            }
            printf("%lld\n",ans);
            continue;
        }
        ans=0;
        dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
