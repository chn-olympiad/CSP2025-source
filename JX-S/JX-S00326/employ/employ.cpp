#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
bool s[505];
int c[505];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        char t;
        cin >> t;
        if(t=='1')
            s[i]=true;
        else
            s[i]=false;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        if(c[i]==0)
            n--;
    }
    if(n<m)
        cout << 0;
    else
    {
        int ans=1;
        for(int i=1;i<=m;i++)
        {
            ans=(ans*i)%MOD;
        }
        cout << ans;
    }
    return 0;
}
