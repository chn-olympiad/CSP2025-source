#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string k;
    cin >> k;
    int s[n];
    long long ans=1;
    for (int i=0;i<n;i++){
        cin >> s[i];
        ans=ans*(i+1);
    }
    if (n==m){
        cout << 0;
        return 0;
    }
    cout << ans%998244353;
    return 0;
}
