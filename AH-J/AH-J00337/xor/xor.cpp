#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int tot = 0,h = 0,q = 0,l,r;
int n;
int main()
{
    freopen("xor.in","i",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout >> l >> r;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    if(tot < (l*n) || tot > (r*n))
    {
        cout << -1;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i] < l) h += l - a[i];
            if(a[i] > r) q += a[i] - r;
        }
    }
    cout << max(h,q);
    return 0;
}
