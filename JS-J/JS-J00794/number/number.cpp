#include<bits/stdc++.h>
using namespace std;//100
const int N = 1e6 + 6;
int a[N];
int tot = 0;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            a[++tot] = int(s[i] - '0');
        }
    }
    sort(a + 1, a + tot + 1, greater<int>());
    for(int i = 1; i <= tot; i++) cout << a[i];
    cout << "\n";
    return 0;
}
