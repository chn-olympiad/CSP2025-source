#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    int v[5];
    int id;
}a[100005];
bool cmp_a(node a,node b)
{
    return a.v[1]>b.v[1];
}
bool cmp_b(node a,node b)
{
    return a.v[2]>b.v[2];
}
void special_a()
{
    sort(a+1,a+n+1,cmp_a);
    int sum=0;
    for(int i=1;i<=n/2;i++)
    {
        sum+=a[i].v[1];
    }
    cout<<sum<<endl;
}
int ans;
void bfs()
{
    priority_queue<pair<int,pair<int,pair<int,pair<int,int> > > > > q;
    q.push({0,{0,{0,{0,1}}}});
    while(!q.empty())
    {
        int now=q.top().second.second.second.second;
        int w1=q.top().second.first,w2=q.top().second.second.first,w3=q.top().second.second.second.first;
        int sum=q.top().first;
        q.pop();
        if(now>n)
        {
            ans=sum;
            break;
        }
        if(w1<n/2)q.push({sum+a[now].v[1],{w1+1,{w2,{w3,now+1}}}});
        if(w2<n/2)q.push({sum+a[now].v[2],{w1,{w2+1,{w3,now+1}}}});
        if(w3<n/2)q.push({sum+a[now].v[3],{w1,{w2,{w3+1,now+1}}}});
    }
}
void dfs(int x,int w1,int w2,int w3,int sum)
{
    if(x>n)
    {
        ans=max(ans,sum);
        return;
    }
    if(w1<n/2)dfs(x+1,w1+1,w2,w3,sum+a[x].v[1]);
    if(w2<n/2)dfs(x+1,w1,w2+1,w3,sum+a[x].v[2]);
    if(w3<n/2)dfs(x+1,w1,w2,w3+1,sum+a[x].v[3]);
}
int dp[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int tsk;
    cin>>tsk;
    while(tsk--)
    {
        ans=0;
        memset(a,0,sizeof(a));
        bool special_a_ok=1,special_b_ok=1;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].v[1]>>a[i].v[2]>>a[i].v[3];
            a[i].id=i;
            if(a[i].v[2]!=0)special_a_ok=0;
            if(a[i].v[3]!=0)special_a_ok=special_b_ok==0;
        }
        if(special_a_ok)special_a();
        else if(n<=18)
        {
            dfs(1,0,0,0,0);
            cout<<ans<<endl;
        }
        else
        {
            bfs();
            cout<<ans<<endl;
        }
    }
}
/*



*/
