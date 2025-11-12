#include <iostream>
#include <cstdio>
using namespace std;
string s;
int n,m,c[505],ans[505],cnt,failed,num;
bool vis[505];
void dfs(int k)
{
    if(k>=n)
    {
        failed=num=0;
        for(int i=0;i<n;i++)
        {
            if(failed>=ans[i]||s[i]=='0')
            {
                failed++;
                continue;
            }
            num++;
        }
        if(num>=m)
        {
            cnt++;
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            ans[k]=c[i];
            vis[i]=1;
            dfs(k+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> m >> s;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
    }
    dfs(0);
    cout << cnt;
    return 0;
}
