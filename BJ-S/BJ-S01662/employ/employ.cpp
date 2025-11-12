#include<bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m,sum;
int c[505],a[505];
const int mod=998244353;
string s;

void solve()
{
    if(sum!=n)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(c[i]=='0')
        {
            cout<<0<<'\n';
            return;
        }
    }
    long long mul=1;
    for(int i=1;i<=n;i++)
    {
        mul*=i;
        mul%=mod;
    }
    cout<<mul<<'\n';
    return;
}

void sol2()
{
    long long mul=1;
    for(int i=1;i<=n;i++)
    {
        mul*=i;
        mul%=mod;
    }
    cout<<mul<<'\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    s=' '+s;
    sum=0;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        if(s[i]=='1') sum++;
    }
    if(sum==0)
    {
        cout<<0<<'\n';
        return 0;
    }
    if(m==n)
    {
        solve();
        return 0;
    }
    if(n>18&&sum==n)
    {
        sol2();
        return 0;
    }
    int ans=0;
    do
    {
        int cnt=0,us=0;
        for(int i=1;i<=n;i++)
        {
            if(cnt>=c[a[i]])
            {
                cnt++;
                continue;
            }
            if(s[i]=='0')
            {
                cnt++;
                continue;
            }
            us++;
        }
        if(us>=m) ans++;
    }while(next_permutation(a+1,a+n+1));
    cout<<ans<<'\n';
    return 0;
}




