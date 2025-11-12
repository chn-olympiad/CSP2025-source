#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5, M=1e4+5, Mod=998244353;
int n, m, c[M], cn, ans=1, c2;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m >> s;
    for(int i=1;i<=n;i++){
        cin >> c[i];
        if(c[i]==0) cn++;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            c2++;
        }
    }
    if(cn>n-m||c2<m){
        cout << 0;
    }else{
        cout << 1;
    }
    return 0;
}
