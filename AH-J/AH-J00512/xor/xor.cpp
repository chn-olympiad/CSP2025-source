#include <iostream>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int a[N];
signed main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    int mx = -1, mn = 0x3f3f3f3f, cnt1 = 0, cnt0 = 0;
    bool flag = true, t = true;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        if(a[i] != 1){
            flag = false;
        }
        if(a[i] > 1){
            t = false;
        }
        if(a[i] == 1){
            cnt1++;
        }else if(a[i] == 0){
            cnt0++;
        }
    }
    if(flag){
        if(k == 1){
            cout<<n;
        }else if(k == 0){
            cout<<n / 2;
        }
    }else if(t){
        if(k == 1){
            cout<<cnt1;
        }else if(k == 0){
            cout<<cnt1 / 2 + cnt0;
        }
    }
    return 0;
}
