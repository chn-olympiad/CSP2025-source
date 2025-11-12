#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m,mod=998244353;
bool flag[100];
long long a[100],t2[100],pos[100],ans;
void dfs(long long u)
{
    if(u>n)
    {
        long long h=0,res=0;
        for(long long i=1;i<=n;i++)
        {
            if(t2[i]==1 && h<a[pos[i]])
            {
                res++;
            }
            else
            {
                h++;
            }
        }
        if(res>=m)
        {
            ans++;
            ans%=mod;
        }
        return;
    }

    for(long long i=1;i<=n;i++)
    {
        if(flag[i]==0)
        {
            flag[i]=1;
            pos[u]=i;
            dfs(u+1);
            flag[i]=0;
        }
    }

}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    string x;cin>>x;
    long long num0=0,num02=0;
    for(long long i=1;i<=n;i++)
    {
        t2[i]=x[i-1]-'0';
    }

    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];if(a[i]==0)num0++;
        if(t2[i]==0)num02++;
    }
    if(n==m)
    {
        long long res=1;
        if(num0>=1 || num02>=1)
        {
            cout<<0;return 0;
        }
        for(long long i=1;i<=n;i++)
        {
            res*=i;res%=mod;
        }
        cout<<res;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
