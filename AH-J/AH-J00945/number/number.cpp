#include <bits/stdc++.h>
using namespace std; 
vector <int> num; 
string s; 
int main() {
    ios :: sync_with_stdio(false); 
    cin.tie(nullptr), cout.tie(nullptr); 
    freopen("number.in", "r", stdin); 
    freopen("number.out", "w", stdout); 
    cin >> s; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            num.push_back(s[i] - '0'); 
    }
    sort(num.begin(), num.end(), [](int x, int y){
        return x > y; 
    }); 
    if (s[0] == 0) 
        cout << 0 << endl; 
    else {
        for (int i = 0; i < num.size(); i++)
            cout << num[i]; 
        cout << endl; 
    }
    return 0; 
}
