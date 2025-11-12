#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[500010],ans;
bool v[500010];
ll xxor(ll s1,ll s2)
{
    return (s1 | s2) - (s1 & s2);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (ll i = 1;i <= n;i++) cin >> a[i];
    if (k == 0)
    {
        for (ll i = 1;i <= n;i++)
        {
            if (a[i] == 0)
            {
                ans++;
                v[i] = true;
            }
        }
        for (ll i = 1;i <= n;i++)
        {
            if (!v[i])
            {
                ll s = a[i],j = i;
                while (!v[j+1] && j < n){
                    j++;
                    s = xxor(s,a[j]);
                    if (s == 0){
                        ans++;
                        for (int l = i;l <= j;l++) v[l] = true;
                        i = j;
                        break;
                    }
                }
            }
        }
        cout << ans;
    }
    if (k == 1)
    {
        for (ll i = 1;i <= n;i++)
        {
            if (a[i] == 1)
            {
                ans++;
                v[i] = true;
            }
        }
        for (ll i = 1;i <= n;i++)
        {
            if (!v[i])
            {
                ll s = a[i],j = i;
                while (!v[j+1] && j < n){
                    j++;
                    s = xxor(s,a[j]);
                    if (s == 1){
                        ans++;
                        for (int l = i;l <= j;l++) v[l] = true;
                        i = j;
                        break;
                    }
                }
            }
        }
        cout << ans;
    }
    return 0;
}
