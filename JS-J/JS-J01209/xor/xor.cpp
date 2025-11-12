#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, cnt;
ll a[500005];
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == 1) cnt++;
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
