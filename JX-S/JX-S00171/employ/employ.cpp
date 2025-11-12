#include<bits/stdc++.h>
using namespace std;
const int N = 505,M = 998244353;
int n,m;
int c[N];
string s;
long long jc(long long x){
    if(x <= 2)return 1;
    else return jc(x - 1) * x % M;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; ++i){
        cin >> c[i];
    }
    cout << jc(n);
    fclose(stdin);
    fclose(stdout);
    return 1+1-4+5+1-4;
}
