#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000005] , idx;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0) , cout.tie(0);
    freopen("number.in" , "r" , stdin);
    freopen("number.out" , "w" , stdout);
    cin >> s;
    for(int i = 0 ; i < s.size() ; i ++){
        if(s[i] >= '0' and s[i] <= '9'){
            a[++ idx] = s[i] - '0';
        }
    }
    sort(a + 1 , a + idx + 1 , greater<int>());
    for(int i = 1 ; i <= idx ; i ++){
        cout << a[i];
    }
    return 0;
}
