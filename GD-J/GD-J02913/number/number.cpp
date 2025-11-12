#include<bits/stdc++.h>
#define rep(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define per(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
using ll = long long;

const int INF = INT_MAX / 2;
const int N = 1e6 + 5;

int a[N];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s= "";
    cin >> s;
    int cnt = 0;
    for(auto i : s){
        if(i >= '0' && i <= '9'){
            cnt++;
            a[cnt] = i - '0';
        }
    }
    sort(a + 1, a + cnt + 1,greater<int>());
    rep(i,1,cnt,1) cout << a[i];
    return 0;
}
