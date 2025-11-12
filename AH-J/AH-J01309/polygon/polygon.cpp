#include<bits/stdc++.h>
using namespace std;
const int pi=998244353;
int n,ans;
long long a[5003],sum;
void dfs(int i,int x)
{
    if(i>n)
    {
        return ;
    }
    if(sum>a[i])
    {
        ans++;ans=ans%pi;
    }
    sum+=a[i];x++;dfs(i+1,x);
    if(x>0)
    {
        sum-=a[i];x--;dfs(i+1,x);
    }
    return;
}
bool cmp(long long x,long long y)
{
    return x<y;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    if(n==3)
    {
        int t,y,u;
        cin>>t>>y>>u;
        if((t+y+u)>(2*max(max(t,y),u)))
        {
            cout<<1<<endl;return 0;
        }
        else
        {
            cout<<0<<endl;return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
