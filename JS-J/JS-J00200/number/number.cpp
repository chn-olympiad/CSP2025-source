//欸我竟然发现了中文输入法
//有点意思
//8.35ACT1
#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
using namespace std ;
string s ;
ll n , len , i ;
vector<ll> a ;
int main(){
    freopen("number.in","r",stdin) ;
    freopen("number.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> s ;
    len = s.size() ;
    for(i=0;i<len;i++){
        if(s[i]>='0' && s[i]<='9'){
            a.push_back(s[i]-'0') ;
        }
    }
    sort(a.begin(),a.end(),greater<ll>()) ;
    if(a[0]==0){
        cout << 0 ;
        return 0 ;
    }
    for(auto &&k : a){
        cout << k ;
    }
    return 0 ;
}
