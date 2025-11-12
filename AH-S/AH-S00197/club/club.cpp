#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int s1,s2,s3;
}a[1000000];int n;
int maxx=-9999;
void dfs(int tot,int t1,int t2,int t3,int id)
{
    if(id==n+1)
    {
        maxx=max(maxx,tot);
        return;
    }
    if(t1<n/2)
    {
        dfs(tot+a[id].s1,t1+1,t2,t3,id+1);
    }
    if(t2<n/2)
    {
        dfs(tot+a[id].s2,t1,t2+1,t3,id+1);
    }
    if(t3<n/2)
    {
        dfs(tot+a[id].s3,t1,t2,t3+1,id+1);
    }
    return;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));maxx=-9999;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].s1>>a[i].s2>>a[i].s3;
        }
        dfs(0,0,0,0,1);
        cout<<maxx<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
