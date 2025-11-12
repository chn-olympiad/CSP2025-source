#include <iostream>
#include <algorithm>
#include <cstring>
#define N 100005
using namespace std;

bool f1[N];
int f2[5],ans,n,m;

struct fav1
{
    int v1,v2,v3;
}a[N];

int a0[N][5];

bool cmp1(fav1 x, fav1 y)
{
    return x.v3>y.v3;
}

int read()
{
    char c;
    for(c=getchar(); c>'9' || c<'0'; c=getchar());
    int x;
    for(x=0; c>='0' && c<='9'; c=getchar())
    {
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x;
}

void dfs(int k, int sum)
{
    if(k>n)
    {
        ans=max(ans, sum);
    }
    else
    {
        for(int i=1; i<=3; i++)
        {
            if(f2[i]<m)
            {
                ++f2[i];
                dfs(k+1,sum+a0[k][i]);
                --f2[i];
            }
        }
    }
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T=read();
    while(T--)
    {
        n=read();
        if(n<=13)//
        {
            for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=3; j++)
            {
                a0[i][j]=read();
            }
        }
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        ans=0, m=n/2;
        dfs(1,0);
        cout<<ans<<endl;
        }//
        else//
        {
            bool f=0;
            for(int i=1; i<=n; ++i)
        {
            a[i].v1=read();
            a[i].v2=read();
            a[i].v3=read();
            if(a[i].v3!=0)f=1;
        }
            if(f==0)//
            {
                for(int i=1; i<=n; ++i)
        {
            a[i].v3=a[i].v2-a[i].v1;
        }
        sort(a+1,a+1+n,cmp1);
        int m=n/2;
        for(int i=1; i<=n && m>0; ++i)
        {
            a[i].v1=a[i].v2;
            --m;
        }
        ans=0;
        for(int i=1; i<=n; ++i)
        {
            ans+=a[i].v1;
        }
        cout<<ans<<endl;
            }//
            else
            {

            }
        }//

    }
    return 0;
}
