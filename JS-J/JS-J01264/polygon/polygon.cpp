#include <bits/stdc++.h>
using namespace std;
int n,a[5010];
long long ans;
bool b = true;
void d(int x,long long s,int y)
{
    y++;
    s += a[x];
    if (s > 2 * a[x] && y >= 3){
        ans++;
        ans = ans % 998244353;
    }
    for (int i = x + 1;i <= n;i++) d(i,s,y);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        if (a[i] != 1) b = false;
    }
    if (b){
        ans = 1;
        for (int i = 1;i < n;i++)
        {
            ans *= 2;
            ans %= 998244353;
        }
        cout << (ans * 2 - 1) % 998244353;
        return 0;
    }
    sort(a+1,a+1+n);
    for (int i = 1;i <= n;i++) d(i,0,0);
    cout << ans;
    return 0;
}
