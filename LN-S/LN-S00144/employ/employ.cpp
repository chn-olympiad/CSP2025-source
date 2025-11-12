#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],b[510],mb[510],ans=0;
char s[510];
void dfs(int t,int y)
{
    if(y>=m)
    {
        ans++;
        ans%=998244353;
        return ;
    }
    if(t==n+1)
        return ;
    for(int i=1;i<=n;i++)
    {
        if(mb[i]==0)
        {
            mb[i]=1;
            if(t-1-y>=b[i])
                dfs(t+1,y);
            else
                dfs(t+1,y+a[t]);
            mb[i]=0;
        }
    }

}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=500;i++)
        mb[i]=0;
    for(int i=0;i<n;i++)
        a[i+1]=s[i]-'0';
    for(int i=1;i<=n;i++)
        cin>>b[i];
    dfs(1,0);
    cout<<ans;
}
