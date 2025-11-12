#include <bits/stdc++.h>
using namespace std;
vector <int> v;
string s;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> s;
    for(int i = 0;i < s.size();i ++){
        if(s[i] >= '0' && s[i] <= '9'){
            v.push_back(s[i] - '0');
        }
    }
    sort(v.begin(), v.end(), [&](int _, int __){
            return _ > __;
    });
    for(auto it : v){
        cout << it;
    }
    return 0;
}
