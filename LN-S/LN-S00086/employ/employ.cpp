#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int m,n,l,c[510],a[510],ans;
string s;
void p()
{
    int quit=0,cnt=0;
    for(int i=1;i<=n;i++)//a[i] xuhao
    {
        if(quit>=c[a[i]])
        {
            quit++;
            continue;
        }
        if(s[i-1]=='0')
        {
            quit++;
            continue;
        }
        quit=0;
        cnt++;
        if(cnt>=m)
        {
            ans=(ans+1)%mod;
            return;
        }
    }
}
signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    if(m==n)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
    }
    l=s.size();
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
    }
    p();
    while(next_permutation(a+1,a+n+1))
    {
        p();
    }
    cout<<ans;
    return 0;
}

