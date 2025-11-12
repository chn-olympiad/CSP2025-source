#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 5e5 + 5;
int n,k,a[N],ans,now;
signed main(){
    freopen("xor","w",stdin);
    freopen("xor","r",stdout);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        if(a[i] == k){
            ans++;
            if(now) now = 0;
            continue;
        }
        else{
            if(!now)    now = a[i];
            else    now = now ^ a[i];
        }
        if(now == k){
            ans++;
            now = 0;
        }
    }
    cout << ans;
    return 0;
}
