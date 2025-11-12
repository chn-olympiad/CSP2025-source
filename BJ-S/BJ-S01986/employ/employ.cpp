#include<bits/stdc++.h>

using namespace std;

constexpr int N=5e2+5;
constexpr int P=998244353;

string s;

int n,m;
int cnt0,cnt1;
int c[N];
int f[N][N][N];
int ans=0;

signed main()
{
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='0') cnt0++;
        else cnt1++;
    for(int i=1;i<=n;i++) cin>>c[i];
    if(!cnt0)
    {
        ans=1;
        for(int i=1;i<=n;i++) (ans<<=1)%=P;
        cout<<ans;return 0;
    }
    if(n==m)
    {
        if(cnt0) puts("0");
        else
        {
            ans=1;
            for(int i=1;i<=n;i++) (ans<<=1)%=P;
            cout<<ans;return 0;
        }
    }
    f[1][0][0]=(cnt0!=0);f[1][1][(c[1]!=0)]=(cnt1!=0);
    for(int i=2;i<=n;i++)
        for(int j=max(0, i-cnt0);j<=min(i, cnt1);j++)
        {
            int num=i-j;
            for(int k=0;k<=j;k++)
            {
                if(num>=c[i]) f[i][j][k]=(f[i-1][j-1][k]+f[i-1][j][k])%P;
                else f[i][j][k]=((!k?0:f[i-1][j-1][k-1])+f[i-1][j][k])%P;
                //cout<<"f["<<i<<"]["<<j<<"]["<<k<<"]="<<f[i][j][k]<<'\n';
            }
        }
    for(int i=m;i<=cnt1;i++) (ans+=f[n][cnt1][i])%=P;
    cout<<ans;

    return 0;
}
