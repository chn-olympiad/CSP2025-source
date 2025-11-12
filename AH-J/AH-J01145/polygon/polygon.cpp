#include<bits/stdc++.h>
using namespace std;
//map<int,long long> t;
int n,m,a[5005],ans;
void dfs(int i,int j,int cnt,int mx)
{
    if(i==n+1&&j>=3)
    {
        if(cnt>mx+mx)
        {
            ans++;
            return ;
        }
        return ;
    }
    else if(i==n+1&&j<3)
    {
        return ;
    }
    dfs(i+1,j+1,cnt+a[i],max(mx,a[i]));
    dfs(i+1,j,cnt,mx);
    return ;
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
    dfs(0,0,0,0);
    cout<<ans/2;
    return 0;
}
