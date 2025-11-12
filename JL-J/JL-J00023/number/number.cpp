#include<bits/stdc++.h>
using namespace std;
/*<====================>*/
const int N = 1e6;
string s;
int n, a[N], t = 0;
/*<====================>*/
bool mycmp(int a, int b){return a > b;}
/*<====================>*/
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s; n = s.size();
    for(int i = 0; i < n; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            t++;
            a[t] = s[i] - '0';
        }
    }
    sort(a + 1, a + 1 + t, mycmp);
    for(int i = 1; i <= t; i++)
        cout << a[i];
    cout << endl;
    return 0;
}
