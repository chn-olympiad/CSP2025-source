#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[600];
string k;

signed main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> k;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    bool f=1;
    for(int i=0;i<n;i++){
        if(k[i]=='0'){
            f=0;
            break;
        }
    }
    if(f){
        int all=1;
        for(int i=2;i<=n;i++){
            all=(all*i);
        }
        cout << all%998244353;
        return 0;
    }
    return 0;
}
/*
998244353!!!!!!!!!!!!!!!!!
*/







