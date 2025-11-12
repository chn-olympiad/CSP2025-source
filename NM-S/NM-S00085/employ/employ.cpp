#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[5003];
int a[5003],vis[5003];
vector<int>kid;
int sum,cnt,ans;
void dfs(int nw)
{
    if(nw==n+1)
    {
        cnt=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt<a[kid[i-1]]&&s[i]==1)
                sum++;
            else
                cnt++;

        }
        if(sum>=m)
            ans++;
        return;
    }
    for(int i=1;i<=n;i++)
        if(!vis[i])
        {
            kid.push_back(i);
            vis[i]=1;
            dfs(nw+1);
            vis[i]=0;
            kid.pop_back();
        }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%1d",&s[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    dfs(1);
    printf("%d",ans);
    return 0;
}
