#include<bits/stdc++.h>
using namespace std;
int g[1010][1010],ans=2147483647,cur1=10000000,cur2=10000000;
bool d[1010][1010];
bool is(int n)
{
    queue<int>q;
    bool f[10010];
    memset(f,0,sizeof(f));
    while(!q.empty())
    {
        int x=q.front();
        f[x]=1;
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(d[x][i]==1&&f[i]==0)
                q.push(i);
        }
    }
    for(int i=1;i<=n;i++)
        if(!f[i])return 0;
    return 1;
}
void dfs(int s,int m,int n,int sum)
{
    if(s>=m)return;
    if(is(n))
    {
        ans=min(ans,sum);
        return;
    }
    bool f=1;
    for(int i=cur2;i<=n;i++)
    {
        if(g[cur1][i]!=-1)
        {
            f=0;
            cur2=i;
            break;
        }
    }
    if(f)
    {
        cur1++;
        for(int i=cur1;i<=n;i++)
        {
            if(g[cur1][i]!=-1)
            {
                f=0;
                cur2=i;
                break;
            }
        }
    }
    dfs(s+1,m,n,sum);
    d[cur1][cur2]=1;
    dfs(s+1,m,n,sum+g[cur1][cur2]);
    d[cur1][cur2]=0;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=1000;i++)
        for(int j=1;j<=1000;j++)
            g[i][j]=-1;

    if(k==0)
    {
        for(int i=1;i<=m;i++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            if((g[x][y]!=-1&&g[x][y]>z)||g[x][y]==-1)
                g[x][y]=z,g[y][x]=z;
            if(cur1==x)
                cur2=min(cur2,y);
            if(cur1>x)
                cur1=x,cur1=y;
        }
        dfs(0,m,n,0);
        cout<<ans;
    }
	return 0;
}
