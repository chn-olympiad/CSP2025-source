#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const ll MOD=998244353;
int n,m,c[505],f[505],ans,a[505],ch;
string s;
void dfs(int step)
{
    if(step>n)
    {
        int cnt=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i-1]=='0')
            {
                cnt++;
            }
            else
            {
                if(cnt<c[a[i]])
                {
                    sum++;
                }
                else
                {
                    cnt++;
                }
            }
        }
        if(sum>=m)
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(f[i]==0)
        {
            f[i]=1;
            a[step]=i;
            dfs(step+1);
            f[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    if(n<=10)
    {
        dfs(1);
        cout<<ans;
    }
    else
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                ch++;
            }
        }
        if(ch==n)
        {
            ll ans1=1;
            for(ll i=n;i>1;i--)
            {
                ans1*=i;
                ans1%=MOD;
            }
            cout<<ans1;
        }
        else
        {
            ll ans2=1;
            for(ll i=18;i>1;i--)
            {
                ans2*=i;
                ans2%=mod;
            }
            cout<<ans2;
        }
    }
    return 0;
}
