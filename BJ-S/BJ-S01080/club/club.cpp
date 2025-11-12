#include<bits/stdc++.h>
using namespace std;
int n,t,ans,flag;
struct node
{
    int x,y,z;
}a[100005];
void dfs1 (int sum,int a1,int a2,int a3,int dep)
{
    if (dep==n+1)
    {
        ans=max(ans,sum);
        return ;
    }
    if (a1<n/2) dfs1(sum+a[dep].x,a1+1,a2,a3,dep+1);
    if (a2<n/2) dfs1(sum+a[dep].y,a1,a2+1,a3,dep+1);
    if (a3<n/2) dfs1(sum+a[dep].z,a1,a2,a3+1,dep+1);
}
void dfs2 (int sum,int a1,int a2,int dep)
{
    if (dep==n+1)
    {
        ans=max(ans,sum);
        return ;
    }
    if (a1<n/2) dfs2(sum+a[dep].x,a1+1,a2,dep+1);
    if (a2<n/2) dfs2(sum+a[dep].y,a1,a2+1,dep+1);
}
bool cmp(node v,node u)
{
    return v.x>u.x;
}
void dfs3 (int sum,int a1,int dep)
{
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n/2;i++) ans+=a[i].x;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while (t--)
    {
        ans=0,flag=0;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
        for (int i=1;i<=n;i++) if (a[i].z or a[i].y) flag=1;
        if (flag==0)
        {
            dfs3(0,0,1);
            cout<<ans<<endl;
            continue;
        }
        flag=0;
        for (int i=1;i<=n;i++) if (a[i].z) flag=1;
        if (flag==0)
        {
            dfs2(0,0,0,1);
            cout<<ans<<endl;
            continue;
        }
        dfs1(0,0,0,0,1);
        cout<<ans<<endl;
    }
    return 0;
}
