#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int u,v,w;
}a[1000001];
bool cmp(node x,node y)
{
    return x.u>y.u;
}
long long maxn = -1e9;
int n;
void dfs(int x,long long sum,int b,int c,int d)
{
    if(x>n)
    {
        maxn = max(sum,maxn);
        return;
    }
    if(b+1<=n/2)
    {
        dfs(x + 1,sum + a[x].u,b + 1,c,d);
    }
    if(c+1<=n/2)
    {
        dfs(x + 1,sum + a[x].v,b,c + 1,d);
    }
    if(d+1<=n/2)
    {
        dfs(x + 1,sum + a[x].w,b,c,d + 1);
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int f = 1,f1 = 1;
        for(int i = 1;i<=n;i++)
        {
            cin>>a[i].u>>a[i].v>>a[i].w;
            if(a[i].v!=0)
            {
                f = 0;
            }
            if(a[i].w!=0)
            {
                f1 = 0;
            }
        }
        if(f == 1&&f1 == 1)
        {
            sort(a+1,a+n+1,cmp);
            long long sum = 0;
            for(int i = 1;i<=n/2;i++)
            {
                sum+=a[i].u;
            }
            cout<<sum<<endl;
            continue;
        }
        maxn = -1e9;
        dfs(1,0,0,0,0);
        cout<<maxn<<endl;
    }
    return 0;
}
