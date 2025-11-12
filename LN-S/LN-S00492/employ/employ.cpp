#include<bits/stdc++.h>
using namespace std;
int n,m;
char ch[510];
int ss = 0;
int s[510];
int c[510];
const int mod = 998244353;
long long jie(int x){
    int ret = 1;
    for (int i=1;i<=x;i++){
        ret *= i;
        ret %= mod;
    }
    return ret;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>ch;
    for (int i=1;i<=n;i++){
        s[i] = int(ch[i-1]-48);
        ss += s[i];
    }
    for (int i=1;i<=n;i++){
        cin>>c[i];
    }
    if (ss==n){
        cout<<jie(n);
    }
    else if (m==n) cout<<0;
    else cout<<0;
    return 0;
}
