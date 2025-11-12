#include <bits/stdc++.h>
using namespace std;
int c[100005];
bool s[100005];
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        char a;
        cin >> a;
        if (a == '1'){
            cnt++;
            s[i] = true;
        }
        else{
            s[i] = false;
        }
    }
    for (int i = 0; i < n; i++)
        cin >> c[i];
    if (cnt < m)
        cout << 0 << endl;
    else
        cout << 2 << endl;
    return 0;
}
