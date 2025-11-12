#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
ll n,sum,ans = 0;
ll flag = 0;
ll a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if(n == 3){
        ll maxn = -1,sum = 0;
        for(int i = 1;i <= n;i++){
            maxn = max(maxn,a[i]);
            sum += a[i];
        }
        if(sum > 2 * maxn){
            cout << 1;
        }
        else{
            cout << 0;
        }
    }
    return 0;
}
