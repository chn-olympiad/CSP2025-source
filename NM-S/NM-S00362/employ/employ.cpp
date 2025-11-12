#include<bits/stdc++.h>
using namespace std;
int n,m,s[1000000],c[1000000];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        cin >> s[i][j];
    }
    for(int i = 1;i<=n;i++){
        cin >> c[i][j];
    }
    cout << pow(m,n) % 998244353;
    return 0;
}
