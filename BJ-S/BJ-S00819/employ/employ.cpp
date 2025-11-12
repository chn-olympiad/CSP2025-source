#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;

int n,m,p[510];
string s;
int a[20];

void solve1()
{
    for(int i=1;i<=n;i++)
        a[i]=i;
    int ans=0;
    do
    {
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0')cnt++;
            else
            {
                if(cnt>=p[a[i]])cnt++;
            }
        }
        if(n-cnt>=m)ans++;
    }while(next_permutation(a+1,a+n+1));
    cout << ans << '\n';
    exit(0);
}

void solve2()
{
    ll ans=1;
    int cnt=0;
    for(int i=1;i<=n;i++)
        if(p[i]!=0)cnt++;
    for(int i=1;i<=cnt;i++)
    {
        ans=ans*i%mod;
    }
    cout << ans << '\n';
    exit(0);
}

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    s=" "+s;
    for(int i=1;i<=n;i++)
        cin >> p[i];
    if(n<=10)
        solve1();
    solve2();
    return 0;
}