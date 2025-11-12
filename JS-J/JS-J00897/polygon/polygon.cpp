#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int a[5050];
bool vis[5050];
long long cnt;

void dfs(int sum,int num,int ma,int x)//num is now number
{
    if(num==x)
    {
        if(sum>2*ma)
        {
            cnt++;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&a[i]>=ma)
        {
            vis[i]=1;
            dfs(sum+a[i],num+1,a[i],x);
            vis[i]=0;
        }
    }
}

int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        dfs(0,0,0,i);
    }
    cout<<cnt%998244353;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
