#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lli long long int
using namespace std;
class people
{
    public:
        lli a1,a2,a3;

};
people a[100010];
lli dp[10010][10010];
bool cmp1(people awa,people qwq)
{
    return awa.a1>qwq.a1;
}
bool cmp2(people awa,people qwq)
{
    return awa.a2>qwq.a3;
}
bool cmp3(people awa,people qwq)
{
    return awa.a3>qwq.a3;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    lli ak;
    cin>>ak;
    while(ak--)
    {
        lli n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i].a1>>a[i].a2>>a[i].a3;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=max(max(dp[i-1][j-1]+a[i].a1,dp[i-1][j]+a[i].a2),dp[i-1][j]+a[i].a3);
            }
        }
        lli maxn=-114514;
        for(int i=1;i<=n;i++)
        {
            maxn=max(maxn,dp[i][n]);
        }
        cout<<maxn<<endl;
    }
    return 0;
}
