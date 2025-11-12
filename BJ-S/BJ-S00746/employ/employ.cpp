#include<iostream>
#include<cstring>
using namespace std;
int mod=998244353;
int n,m,c[502],vis[502],s[502];
string tm;
int dfs(int d,int k)
{
    int ans=0;
    if(k>n-m)return 0;
    if(d>n)return 1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            if(tm[d-1]=='0'||k>=c[i])
            {
                ans+=dfs(d+1,k+1);
            }
            else
            {
                ans+=dfs(d+1,k);
            }
            vis[i]=0;
        }
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>tm;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    cout<<dfs(1,0);
    return 0;
}