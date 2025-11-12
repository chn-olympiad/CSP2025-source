#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int t,n,ta,tb,tc,ans=0,maxx=-1;
struct student
{
    int a,b,c;
    bool x;
}p[100005];
void dfs(int dep,int v,int tta,int ttb,int ttc)
{
    if(dep>n)
    {
        if(v>maxx)
        {
            maxx=v;
        }
    }
    else
    {
        if(tta<n/2)
        {
            dfs(dep+1,v+p[dep].a,tta+1,ttb,ttc);
        }
        if(ttb<n/2)
        {
            dfs(dep+1,v+p[dep].b,tta,ttb+1,ttc);
        }
        if(ttc<n/2)
        {
            dfs(dep+1,v+p[dep].c,tta,ttb,ttc+1);
        }
    }
}
signed main(void)
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i].a>>p[i].b>>p[i].c;
        }
        dfs(1,0,0,0,0);
        cout<<maxx<<endl;
        maxx=-1;
    }
    return 0;
}
