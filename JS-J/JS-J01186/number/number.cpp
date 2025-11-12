#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 1e6 + 7;
string s;
int idx, a[N];
bool cmp(int a, int b){
    return a > b;
}
signed main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s;
    int l = s.size();
    for(int i = 0; i < l; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            idx++;
            a[idx] = s[i] - '0';
        }
    }
    sort(a + 1, a + idx + 1, cmp);
    for(int i = 1; i <= idx; i++){
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
