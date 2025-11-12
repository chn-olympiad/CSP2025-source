#include <bits/stdc++.h>
using namespace std;
const long long mod=998244353;
vector<int> a;
long long sum;
long long ans;
int maxA,n;
vector<int> cho;
vector<bool> vis;
void dfs(int x)
{
    if(cho.size()>=3&&sum>maxA*2)
    {
        ans++;
        ans%=mod;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=true;
            cho.push_back(i);
            int tmp=maxA;
            maxA=max(maxA,a[i]);
            sum+=a[i];
            dfs(i);
            cho.pop_back();
            sum-=a[i];
            maxA=tmp;
            vis[i]=false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    a.resize(n+1);
    vis.resize(n+1,false);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dfs(0);
    cout<<ans;
    return 0;
}
