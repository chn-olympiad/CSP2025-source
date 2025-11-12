#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],f=0,b[505],t=0;
long long p=998244353,ans;
string s;
bool v[505];
void dfs(int st)
{
    if(st==n+1)
    {
        int e=0,d=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0'||e>=a[b[i]])
            {
                e++;
            }
            else
            {
                d++;
            }
        }
        if(d>=m)
        {
            ans=(ans+1)%p;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i])
        {
            v[i]=1;
            b[st]=i;
            dfs(st+1);
            v[i]=0;
        }
    }
    return;
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        v[i]=0;
        if(a[i]==0) t++;
        if(s[i-1]=='1') f++;
    }
    if(f-max(0,t-(n-f))<m)
    {
        cout<<0;
        return 0;
    }
    ans=0;
    dfs(1);
    cout<<ans%p;
    return 0;
}
