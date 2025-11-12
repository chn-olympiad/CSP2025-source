#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m;
string s;
int hd,ez;
int a[510],b[510],x;
long long ans=0;
void dfs(int day,int run)
{
    if(day==n+1)
    {
        if(n-run>=m)
        {
            ans=(ans+1)%mod;
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        //cout<<day<<" "<<run<<endl;
        if(!b[i])
        {
            if(run>=a[i])
            {
                //cout<<"RUN "<<i<<endl;
                b[i]=1;
                dfs(day+1,run+1);
                b[i]=0;
                continue;
            }
            if(s[day-1]=='1')
            {
                //cout<<"YES "<<i<<endl;
                b[i]=1;
                dfs(day+1,run);
                b[i]=0;
            }
            else{
                //cout<<"NO "<<i<<endl;
                b[i]=1;
                dfs(day+1,run+1);
                b[i]=0;
            }
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
        b[i]=0;
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0')
        {
            hd++;
        }
        else
        {
            ez++;
        }
    }
    if(ez==n)
    {
        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }
        cout<<ans<<endl;
    }
    else if(hd==n||ez<m)
    {
        cout<<0<<endl;
    }
    else if(m==n)
    {

        ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }
        cout<<ans<<endl;
    }
    else{
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
