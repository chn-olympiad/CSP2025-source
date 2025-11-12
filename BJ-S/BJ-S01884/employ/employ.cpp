#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[12],ans;
string s;
bool f[12];
void dfs(int l,int mus)
{
    if(l>=n)
    {
        if(n-mus>=m)ans=(ans+1)%998244353;
        return;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
           if(f[i])continue;
           f[i]=1;
           if(s[l]=='0'||mus>=c[i])
           {
               mus++;
           }
           dfs(l+1,mus);
           if(s[l]=='0'||mus>=c[i])
           {
               mus--;
           }
           f[i]=0;
        }
    }
    return;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}
