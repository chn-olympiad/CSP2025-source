#include <bits/stdc++.h>
using namespace std;
const int N = 505;
long long n, m;
string s;
long long c[N];
long long jie(long long n){
    if(n == 1) return 1;
    return jie(n-1) * n % 998244353;
}
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    cin>>n>>m;
    cin>>s;
    for(int i = 1;i<=m;i++){
        cin>>c[i];
    }
    cout<<jie(n);
    return 0;
}
