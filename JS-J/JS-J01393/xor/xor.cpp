#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 7;
int n, k, lst, ans, pre[N], a[N];
ll sum[N];
map<ll,int> mp;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i-1] ^ a[i];
    mp[0] = 1;
    for(int i = 1; i <= n; i++){
        pre[i] = mp[sum[i]^k];
        mp[sum[i]] = i+1;
    }
    for(int i = 1; i <= n; i++){
        if(pre[i] > lst) lst = i, ans++;
    }
    cout << ans << endl;
    return 0;
}
