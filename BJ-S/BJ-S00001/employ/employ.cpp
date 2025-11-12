#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    unsigned long long n, m;
    cin >> n >> m;
    unsigned long long ans=1;
    for(int i=n; i>m; i--){
        ans = ((ans*i)%998244353);
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
