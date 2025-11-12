#include<bits/stdc++.h>
using namespace std;
bool test_case_A=1;
const long long mod=998244353;
int n,m,ans,c[520],p[520];
long long fac[520];
bool dt[520];
string s;
bool used[520];
bool check()
{
    int cnt=0,i;
    for(i=1;i<=n;i++)
    {
        if(!dt[i]||cnt>=c[p[i]])
        {
            cnt++;
            continue;
        }
    }
    return cnt<=n-m;
}
void dfs(int lev)
{
    int i;
    if(lev>n)
    {
        ans+=check();
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i]=1;
            p[lev]=i;
            dfs(lev+1);
            used[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int cnt0=0,i,j;
    cin>>n>>m>>s;
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
        dt[i]=s[i-1]-'0';
        test_case_A&=dt[i];
    }
    if(m==n)
    {
        fac[0]=1;
        for(i=1;i<=n;i++)
        {
            fac[i]=fac[i-1]*i%mod;
            cnt0+=!c[i];
        }
        if(!test_case_A||cnt0)
            puts("0");
        else
            cout<<fac[n]<<endl;
        return 0;
    }
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
