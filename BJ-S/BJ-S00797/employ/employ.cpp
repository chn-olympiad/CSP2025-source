#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int mod = 998244353;
int c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m,zcnt = 0;
    cin >> n >> m;
    string a;
    getline(cin,a);
    getline(cin,a);
    bool flagA = true;
    for(int i = 0;i < a.length();i ++) if(a[i] != '1') flagA = false;
    for(int i = 0;i < n;i ++){
        cin >> c[i];
        if(c[i] == 0) zcnt ++;
    }
    sort(c,c + n);
    if(flagA){
        long long ans = 1;
        for(int i = n - zcnt;i > 1;i --){
            cout << ans << " ";
            ans *= i;
            ans %= mod;
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
