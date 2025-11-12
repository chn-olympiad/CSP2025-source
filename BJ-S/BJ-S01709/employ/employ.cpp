#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int mod=998244353;
int c[N],num[N],book[N];
int jie[N];
char s[N];
int n,m,ans;
void dfs(int dep)
{
    if(dep==n) 
    {
        int p=0,cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]-'0'==0) p++;
            else
            {
                if(p<num[i]) 
                {
                    cnt++;
                }else p++;
            }
        }
        if(cnt>=m) 
        {
            ans++;
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(book[i]) continue;
        book[i]=1;
        num[dep+1]=c[i];
        dfs(dep+1);
        book[i]=0;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    int flag=1;
    cin>>n>>m;
    cin>>(s+1);
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) flag&=((s[i]-'0')==1);
    if(flag)
    {
        int num=0;
        for(int i=1;i<=n;i++) if(c[i]==0) num++;
        jie[0]=1;
        for(int i=1;i<=n;i++) jie[i]=jie[i-1]*i%mod;
        cout<<jie[n-num]<<endl;
    }
    else
    {
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}