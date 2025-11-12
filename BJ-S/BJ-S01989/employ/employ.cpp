#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],cnt = 1;
string s;
const int maxv = 998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i<= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<= n; i++){
        cnt = cnt * i % mod;
    }
    cout << cnt;
    return 0;
}
