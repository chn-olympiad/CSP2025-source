#include <iostream>
#include <cstdio>
using namespace std;
const int N = 510,mod = 99844353;
int n,m;
int s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    
    for(int i=1;i<=n;i++) cin >> s[i];
    int ans = 1;
    for(int i=1;i<=n;i++){
        ans = (ans * i) % mod;
    }
    cout  << ans;
    return 0;
}
