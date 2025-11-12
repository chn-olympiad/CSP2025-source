#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,mod=998244353;
int c[505];
char s[505];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int k=0;
    cin >> n >> m;
	for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        if(s[i]=='0') k=1;
    }
    int u=0;
	for(int i=1;i<=n;i++)
    {
        cin >> c[i];
        if(c[i]==0) u++;
    }
    if(n-u<m)
    {
        cout << 0;
        return 0;
    }
    if(k==0)
    {
        ll ans=1;
        for(int i=1;i<=n;i++)
        {
            ans=(ans*i)%mod;
        }
        cout << ans;
    }
    else
    {
        cout << random();
    }
    return 0;
}
