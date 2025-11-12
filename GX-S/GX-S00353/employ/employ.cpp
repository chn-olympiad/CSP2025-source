#include<bits/stdc++.h>
using namespace std;
char s[500+10];
int n,m,ts;
int c[500+10];
int pl[500+10];
int vis[500+10];
int ans;
void dfs(int x)
{
    if(x>=n+1)
    {
        int tot=0,cnt=0;
        for(int i=0;i<n;++i)
        {

            if(s[i]=='0' or tot>=c[pl[i+1]])
            {
                tot++;
                continue;
            }
            else if(tot<c[pl[i+1]])cnt++;
            //cout<<"s[i]:"<<s[i]<<" i:"<<i<<" c[pl[i+1]:"<<c[pl[i+1]]<<" tot:"<<tot<<" cnt:"<<cnt<<"\n";
            if(cnt>=m)
            {
                //cout<<"OK cnt="<<cnt<<"\n";
                ans++;
                ans%=998244353;
                break;
            }
        }
        return ;
    }
    for(int i=1;i<=n;++i)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            pl[x]=i;
            dfs(x+1);
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;++i)ts+=(s[i]-'0');
    //cout<<ts<<"\n";
    if(ts==n)
    {
        ans=n;
        for(int i=n-1;i>=1;--i)
        {
            ans=(ans*i)%998244353;
            //cout<<ans<<" ";
        }
        cout<<ans;
        return 0;
    }
    dfs(1);
    cout<<ans;
    return 0;
}
