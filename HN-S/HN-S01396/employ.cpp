#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
string a;
int n,m;
int c[N];
void add(int &x,int y){x=x+y>=mod?x+y-mod:x+y;}
namespace work1
{
    int f[1<<18][20]; //用了集合s，前面被拒绝了j个人
    int pop(int x){return __builtin_popcount(x);}
    int main()
    {
        f[0][0]=1;
        for(int s=1;s<(1<<n);s++)
        {
            int m=pop(s);
            for(int i=0;i<=m;i++)
                for(int j=1;j<=n;j++)
                    if(s>>(j-1)&1)
                    {
                        int op=a[m-1]=='0'||i>=c[j];
                        add(f[s][i+op],f[s^(1<<(j-1))][i]);
                    }
        }
        int ans=0;
        for(int i=0;i<=n-m;i++) add(ans,f[(1<<n)-1][i]);
        cout<<ans;
        return 0;
    }
}
namespace work2
{
    int f[N][N]; //当前在i，还有j个可以填的位置
    int main()
    {
        sort(c+1,c+1+n,greater<int>());
        f[0][count(a.begin(),a.end(),'0')]=1;
        int p=n;
        for(int i=0;i<n;i++)
        {
            if(i==1||c[i+1]!=c[i])
            {
                int cnt=0;
                while(p>c[i+1]) cnt+=a[--p]=='1'; 
                for(int j=n;j>=0;j--)
                    if(j>=cnt) f[i][j]=f[i][j-cnt];
                    else f[i][j]=0;
            }
            for(int j=1;j<=n;j++)
                add(f[i+1][j-1],f[i][j]*j%mod);
        }
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        add(ans,mod-f[n][0]);
        cout<<ans;
        return 0;
    }
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    cin>>a;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(n<=18) return work1::main();
    if(n==m)
    {
        if(count(a.begin(),a.end(),'0')||count(c+1,c+1+n,0))
        {
            cout<<0;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++) ans=ans*i%mod;
        cout<<ans;
        return 0;
    }
    if(m==1) return work2::main();
    return 0;
}