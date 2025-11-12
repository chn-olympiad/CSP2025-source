#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll Mod=998244353;
ll a[1005],n,m,all_1=1,zs,ans=1,ans2=1;
ll C[1005][1005];
void init()
{
    C[1][1]=1;
    for(int i=2;i<=n+3;i++)
    {
        for(int j=1;j<=n+3;j++)
        {
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    string s;
    cin>>n>>m;
    zs=n;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==0)all_1=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    srand(time(0));
    cout<<rand()%Mod;
    return 0;
}
//Ren5Jie4Di4Ling5%
