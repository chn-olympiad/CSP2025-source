#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll N = 5e2+5,mod = 998244353;

ll n,m,a[N],c[N],ans,pai[N];
string s;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) pai[i] = i;
    cin >> s;
    for(ll i=1;i<=n;i++) cin >> c[i];
    sort(c+1,c+1+n);
    do
    {
        ll cnt = 0,sb = 0;
        for(ll i=1;i<=n;i++)
        {
            int pos = pai[i];
            if(sb>=c[pos])
            {
                ++sb;
                continue;
            }
            if(s[i-1]=='0') ++sb;
            else ++cnt;
        }
        if(cnt>=m) ans = (ans+1)%mod;
    }while(next_permutation(pai+1,pai+1+n));
    cout << ans;
    return 0;
}
