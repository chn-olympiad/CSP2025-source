#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
string s;
ll a[N], l;
bool cmp(ll a1, ll b1){
    return a1 > b1;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for(ll i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9'){
            a[++l] = s[i] - '0';
        }
    }
    stable_sort(a + 1, a + 1 + l, cmp);
    for(ll i = 1; i <= l; i++){
        cout << a[i];
    }
    return 0;
}
