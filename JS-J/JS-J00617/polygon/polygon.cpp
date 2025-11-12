#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a[5005],ans = 0;
bool b[5005];
inline void dfs(int l)
{
    if(l == n+1)
    {
        LL Max=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(b[i] == 0) continue;
            Max = max(a[i],Max);
            sum+=a[i];
        }
        if(sum > Max*2) ans++;
        return;
    }
    b[l] = 1;
    dfs(l+1);
    b[l] = 0;
    dfs(l+1);
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    dfs(1);
    cout << ans%998244353;
    return 0;
}
