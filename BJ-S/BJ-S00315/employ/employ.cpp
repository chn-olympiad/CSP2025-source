#include<iostream>
using namespace std;
int n,m,c[505],ans;
string s;
bool vis[505];
void dfs(int x,int cnt,int cg)
{
    if(x==n)
    {
        if(cnt>=m)++ans;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(x+1,cnt+(s[x]=='1'&&cg<c[i]?1:0),cg+(s[x]=='1'&&cg<c[i]?0:1));
            vis[i]=0;
        }
    }
}
int main(void)
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
