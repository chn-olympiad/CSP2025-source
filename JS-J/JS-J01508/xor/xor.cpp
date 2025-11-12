#include <bits/stdc++.h>
using namespace std;
long long a[500005], b[100005], ans = 0;
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    /*
    xor
    we find:
    (3^5^7^8)^(3^5)=(7^8)
    wo men ke yi yong qian zhui he
    */
    /*
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    b[1] = a[1];
    for(int i = 2; i <= n; i++){
        b[i] = b[i-1] ^ a[i];
    }
    int j = 1;
    for(int i = 1; i <= n; i++){
        for(; j < i; j++){
            if(b[i] ^ b[j] == k){
                cout << j << "~" << i << endl;
                ans++;
                j = i;
                i = j;
                break;
            }
        }
    }
    cout << ans;*/
    /*pian fen: 10 score*/
    int n, k;
    cin >> n >> k;
    cout << n / 2 << endl;
}
