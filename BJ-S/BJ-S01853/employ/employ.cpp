#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],b[501];
string c;
int mod=998244353;
int dfs(int lu,int weilu)
{
    if(lu+weilu==n)
    {
        if(lu>=m)
        {
            return 1;
        }
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int ann;
        if(b[i]==0)
        {
            b[i]=1;
            if(c[lu+weilu]=='1'&&weilu<a[i])
            {
                ann=dfs(lu+1,weilu);
            }
            else
            {
                ann=dfs(lu,weilu+1);
            }
            b[i]=0;
            ann%=mod;
            /*if(ann==0)
            {
                break;
            }*/
            ans+=ann;
            ans%=mod;
        }
    }
    return ans;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<dfs(0,0);
    return 0;
}