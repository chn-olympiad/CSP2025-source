#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string ss;
int c[550],jiec[550];
int f[20][(1<<18)];
int get(int s)
{
    int ans=0;
    for (int i=0;i<n;i++) ans+=s/(1<<i)%2;
    return ans;
}
void init()
{
    jiec[0]=1;
    for (int i=1;i<=500;i++) jiec[i]=jiec[i-1]*i;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >>n>>m>>ss;
    for (int i=1;i<=n;i++) cin >>c[i];
    init();
    if(n<=18)
    {
        f[0][0]=1;
        for (int s=0;s<(1<<n);s++)
        {
            int ll=get(s);
            for (int i=1;i<=n;i++)
            {
                int y=(s&(1<<i-1));
                if(!y) continue;
                //cout<<i<<" "<<s<<endl;
                int x=s-(1<<i-1);
                for (int j=0;j<=n;j++)
                {
                    if(!f[j][x]) continue;
                    if(c[i]<=j||ss[ll-1]=='0') f[j+1][s]+=f[j][x];
                    else f[j][s]+=f[j][x];
                    f[j+1][s]%=mod;
                    f[j][s]%=mod;
                    //cout<<i<<" "<<j<<" "<<s<<" "<<ll<<" "<<x<<" "<<f[j+1][s]<<" "<<f[j][s]<<endl;
                }
            }
        }
        int ans=0;
        for (int i=0;i<=n-m;i++) ans+=f[i][(1<<n)-1];
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        for (int i=0;i<ss.size();i++)
        {
            if(ss[i]!='1')
            {
                cout<<0;
                return 0;
            }
        }
        for (int i=1;i<=n;i++)
        {
            if(c[i]==0)
            {
                cout<<0;
                return 0;
            }
        }
        cout<<jiec[n];
        return 0;
    }
    int cnt=0,cnt1=0;
    for (int i=1;i<=n;i++) if(c[i]==0) cnt++;
    for (int i=0;i<ss.size();i++) if(ss[i]=='0') cnt1++;
    if(cnt>n-m||cnt1>n-m)
    {
        cout<<0;
        return 0;
    }
    cout<<jiec[n];
    return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
