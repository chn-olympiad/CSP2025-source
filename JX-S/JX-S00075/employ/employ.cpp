#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ok[105],ans;
string s;
void dfs(int d,int k)
{
    if(k>n-m)return;
    if(d==n)ans++;
    for(int i=1;i<=n;i++)
    {
        if(ok[i])continue;
        if(k>=a[i] or s[d]==48)
        {
            ok[i]=1;
            dfs(d+1,k+1);
            ok[i]=0;
        }
        else
        {
            ok[i]=1;
            dfs(d+1,k);
            ok[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    if(n<=18)dfs(0,0);
    cout<<ans;
    return 0;
}
