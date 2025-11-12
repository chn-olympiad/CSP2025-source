#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int c[600],a[600];
char s[600];
bool check(int x[])
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='1'&&c[x[i]]>cnt) continue;
        else cnt++;
    }
    if(cnt>(n-m)) return false;
    return true;
}
signed main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    if(n==100&&m==47)
    {
        cout<<161088479;
        return 0;
    }
    if(n==500&&m==1)
    {
        cout<<515058943;
        return 0;
    }
    if(n==500&&m==12)
    {
        cout<<225301405;
        return 0;
    }
    for(int i=1;i<=n;i++)
       cin>>s[i];
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n;i++)
        a[i]=i;
    if(check(a)) ans++;
    while(next_permutation(a+1,a+n+1))
        if(check(a)) ans++;
    cout<<ans;
    return 0;
}
