#include<bits/stdc++.h>
using namespace std;
int n,ans;
priority_queue<int,vector<int>,greater<int> > q[4];
struct node
{
    int x,id;
}c[4];
bool cmp(node x,node y)
{
    return x.x>y.x;
}
void solve()
{
    int x;
    ans=0;
    for(int i=1;i<=3;i++)
    {
        while(!q[i].empty())q[i].pop();
    }
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++)
        {
            scanf("%d",&x);
            c[j]={x,j};
        }
        sort(c+1,c+4,cmp);
        q[c[1].id].push(c[1].x-c[2].x);
        ans+=c[1].x;
    }
    for(int i=1;i<=3;i++)
    {
        while(q[i].size()>n/2)
        {
            ans-=q[i].top();
            q[i].pop();
        }
    }
    printf("%d\n",ans);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
}