#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0,a[500010];
bool b[500010];
void dfs(int depth,int sum,int num)
{
    bool flag=false;
    if(sum==k&&!b[num])
    {
        ans++;
        flag=true;
        return;
    }
    if(num>n)
    {
        return;
    }
    dfs(depth+1,sum^=a[num],num+1);
    b[num]=true;
    if(!flag)
    {
        b[num]=false;
    }
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        dfs(0,a[i],i);
    }
    cout<<ans;
    return 0;
}
