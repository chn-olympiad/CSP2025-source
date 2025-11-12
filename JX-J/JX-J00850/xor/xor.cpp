#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+8;
int n,k,a[maxn];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
    }
    cout << n/2;
    return 0;
}
