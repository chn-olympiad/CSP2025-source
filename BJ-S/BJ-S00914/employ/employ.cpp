#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],ans[510],answer;
int modee=998244353;
bool used[510];
string s;
void check()
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i-1]=='0')
        {
            sum++;
            continue;
        }
        if(a[ans[i]]<=sum)
        {
            sum++;
            continue;
        }
    }
    if(n-sum>=m)
        answer=(answer+1)%modee;
}
void dfs(int k)
{
    if(k==n+1)
    {
        check();
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==true)
            continue;
        used[i]=true;
        ans[k]=i;
        dfs(k+1);
        used[i]=false;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    cout<<answer;
    return 0;
}
