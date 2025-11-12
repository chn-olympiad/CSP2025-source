#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];
bool cmp(int x, int y){
    return x > y;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    string s;
    getline(cin, s);
    int len = s.size();
    int cnt = 0;
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[++cnt] = (s[i] - '0');
        }
    }
    sort(a + 1, a + cnt + 1, cmp);
    for(int i = 1;i <= cnt;i++){
        cout << a[i];
    }
    return 0;
}
//expect:100pts
//expect total:234pts
