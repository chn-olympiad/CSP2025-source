//T3好变异啊
//我似乎可以建一颗线段树来优化区间DP
//不对区间异或似乎可以用前缀和？
//是可以
//那就可以n^2
//但还是不行
#include <bits/stdc++.h>
#define ll long long
#define isok cout << "ok" << endl
using namespace std ;
const ll MAXN = 100005 ;
ll n ;
int main(){
    freopen("xor.in","r",stdin) ;
    freopen("xor.out","w",stdout) ;
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
    cin >> n ;
    cout << n/2 ;
    return 0 ;
}
