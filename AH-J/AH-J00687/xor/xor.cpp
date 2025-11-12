#include <iostream>
using namespace std;
int a[1000005],sum[1000005];
int n,k;

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        sum[i] = a[i] ^ sum[i-1];
    }
    int maxn = -1;
    for (int i = 1;i <= n;i++){
        int p = i-1,q = i,ans = 0;
        while (q <= n){
            int d = sum[p] ^ sum[q];
            if (d == k){
                ans++;
                p = q;
            }
            q++;
            //cout << (sum[4] ^ sum[3]) << endl;
            //if (ans >= maxn) cout << p << " " << q << " " << ans << endl;

        }
        //if (q == 0) ans++;
        if (maxn <= ans) maxn = ans;
        //cout << "com" << p << " " << q << " " << i << " " << ans << endl;
    }

    //cout << (sum[547]^sum[603])<< endl;
    cout << maxn;

}
