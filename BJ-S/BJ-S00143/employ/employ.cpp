#include<bits/stdc++.h>
using namespace std;
long long c[502],tmp[502];
bool cm[502];
char s[502];
long long n,m,ans=0,mod=998244353;
void DFS(long long x,bool pan[])
{
    if(x==n+1)
    {
        long long cnt=0,fail=0;
        for(long long i=1;i<=n;i++)
        {
            if(fail>=c[tmp[i]])
                continue;
            else if(s[i]=='1')
                cnt++;
            else
                fail++;
        }
        ans+=(cnt>=m),ans%=mod;
        return;
    }
    for(long long i=1;i<=n;i++)
    {
        if(!pan[i])
        {
            pan[i]=true;
            tmp[x]=i;
            DFS(x+1,pan);
            pan[i]=false;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
        cin>>s[i];
    for(long long i=1;i<=n;i++)
        cin>>c[i];
    if(n<=10)
    {
        DFS(1,cm);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}