#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int n, m, cnt;
int c[N];
string s;
int A(int x, int y){
    int num = 1;
    for(int i = x; i >= 1; i--){
        num = num * i;
        num %= 998244353;
    }
    return num;
}
signed main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1; i <= n; i++){
        cnt += s[i]-'0';
    }
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    cnt = n - cnt;
    if(cnt < m){
        cout<<A(m, m)<<'\n';
        return;
    }
    cout<<n<<'\n';
    return 0;
}
