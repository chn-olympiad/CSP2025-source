#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int t,n,ans;
struct node{
    int num,cha,id;
}x[N],y[N],z[N];
void dfs(int pos,int cx,int cy,int cz,int sum)
{
    if(pos>n)
    {
        ans=max(ans,sum);
    }
    if(cx<n/2) dfs(pos+1,cx+1,cy,cz,sum+x[pos].num);
    if(cy<n/2) dfs(pos+1,cx,cy+1,cz,sum+y[pos].num);
    if(cz<n/2) dfs(pos+1,cx,cy,cz+1,sum+z[pos].num);
    return ;
}
bool flag;
bool cmp1(node x,node y)
{
    x.num>y.num;
}
bool cmp2(node x,node y)
{
    x.cha>y.cha;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        ans=0;
        scanf("%lld",&n);
        for(int i=1; i<=n; i++)
        {
            scanf("%lld%lld%lld",&x[i].num,&y[i].num,&z[i].num);
            x[i].cha=x[i].num-y[i].num;
            if(y[i].num) flag=true;
        }
        if(n<=10)
        {
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
        if(n>=100000&&!flag)
        {
            sort(x+1,x+n+1,cmp1);
            for(int i=n; i>=n/2+1; i--) ans+=x[i].num;
            cout<<ans<<endl;
        }
        else if(n>=100000)
        {
            sort(x+1,x+n+1,cmp2);
            for(int i=1; i<=n/2; i++) ans+=x[i].num;
            for(int i=n/2+1; i<=n; i++) ans+=y[x[i].id].num;
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
