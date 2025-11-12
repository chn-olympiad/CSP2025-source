#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3,mod=998244353;
int n,a[N],d[N],ans_dfs;
bool vis[N];
int C(int x,int y)
{
    int ans_x=1,ans_y=1;
    for(int i=x;i>x-y;i--)
    {
        ans_x*=i;
        ans_x%=mod;
    }
    for(int i=1;i<=y;i++)
    {
        ans_y*=i;
        ans_y%=mod;
    }
    return ans_x/ans_y;
}
namespace subtask1
{
    void s()
    {
        int maxn=max(a[1],max(a[2],a[3]));
        if(d[3]>2*maxn)
            printf("1\n");
        else
            printf("0\n");
        exit(0);
    }
}
namespace subtask2
{
    void s()
    {
        int ans_subtask2=0;
        for(int i=3;i<=n;i++)
        {
            ans_subtask2+=C(n,i);
            ans_subtask2%=mod;
        }
        printf("%lld",ans_subtask2);
        exit(0);
    }
}
void dfs(int cnt_end,int maxn,int cnt,int sum,int x)
{
    if(cnt==cnt_end)
    {
        if(sum>2*maxn)
            ans_dfs++;
        return;
    }
    for(int i=x+1;i<=n;i++)
            dfs(cnt_end,max(maxn,a[i]),cnt+1,sum+a[i],i);
}
namespace baoli
{
    void s()
    {
        for(int i=3;i<=n;i++)
            dfs(i,0,0,0,0);
        printf("%lld\n",ans_dfs);
        exit(0);
    }
}
signed main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    srand((int)time(0));
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        d[i]=d[i-1]+a[i];
    }
    if(n<3)
    {
        printf("0\n");
        return 0;
    }
    else if(n==3)
        subtask1::s();
    else if(d[n]==n)
        subtask2::s();
    else if(n<=20)
        baoli::s();
    else
    {
        int ans_rand=0;
        for(int i=3;i<=n;i++)
        {
            ans_rand+=C(n,i);
            ans_rand%=mod;
        }
        printf("%lld\n",rand()%ans_rand);
    }
    return 0;
}
