#include <bits/stdc++.h>
using namespace std;
const int B1 = 1e8 + 7,B2 = 1e9 + 7,M = 998244353;
#define pll pair <long long,long long>
#define fst first
#define scd second
const int N = 2e5 + 5;
string a,b;
map < pair <pll,pll> ,int> mp;
void ins()
{
    int n = a.size(),i = 0;
    for(;i<n && a[i] == b[i];i++);
    pll h = {0,0},h2 = {0,0};
    for(;i<n && a[i] != b[i];i++)
        h.fst = (h.fst*B1%M + a[i])%M,h.scd = (h.scd*B2%M + a[i])%M,
        h2.fst = (h2.fst*B1%M + b[i])%M,h2.scd = (h2.scd*B2%M + b[i])%M;
    mp[{h,h2}]++;
}
int gtan()
{
    int n = a.size(),i = 0;
    for(;i<n && a[i] == b[i];i++);
    pll h = {0,0},h2 = {0,0};
    for(;i<n && a[i] != b[i];i++)
        h.fst = (h.fst*B1%M + a[i])%M,h.scd = (h.scd*B2%M + a[i])%M,
        h2.fst = (h2.fst*B1%M + b[i])%M,h2.scd = (h2.scd*B2%M + b[i])%M;
    return mp[{h,h2}];
}
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++)
    {
        cin >> a >> b;
        ins();
    }
    while(q--)
    {
        cin >> a >> b;
        cout << gtan() <<"\n";
    }
    return 0;
}