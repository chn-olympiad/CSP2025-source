#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 500010;
ll n,k,a[MAXN],b[MAXN];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    b[0] = 0ll;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = b[i - 1] ^ a[i];
        //cout << b[i] << " ";
    }
    //cout << endl;
    int last = 0,ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = last;j <= i - 1;j++){
            if((ll)(b[i] ^ b[j]) == k){
                //cout << 'l' << j + 1 << " r" << i << endl << (ll)(b[i] ^ b[j]) << endl;
                //cout << b[i] ^ b[j] << endl;
                last = i;
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
