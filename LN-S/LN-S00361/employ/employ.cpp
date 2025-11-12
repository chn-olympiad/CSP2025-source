#include<bits/stdc++.h>
using namespace std;
string s;
int a[510];
int b[510];
long long ans;
int p = 998244353;
bool vis[510];
int n,m;
void dfs(int step)
{
    if(step==n+1)
    {
        int cnt=0;
        for(int i = 1;i<=n;i++)
        {
            if(s[i-1]=='0')
            {
                cnt++;
            }
            else
            {
                if(cnt>=a[b[i]])
                {
                    cnt++;
                }
            }
        }
        if(n-cnt>=m)
        {
            ans++;
            ans%=p;
        }
    }
    for(int i = 1;i<=n;i++)
    {
        if(!vis[i])
        {
            b[step]=i;
            vis[i]=true;
            dfs(step+1);
            vis[i]=false;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
