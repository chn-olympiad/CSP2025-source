#include <bits/stdc++.h>

using namespace std;

bool is_int(char c){
    if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return true;
    }
    return false;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    vector<int> nums(10, 0);
    cin >> s;
    int sz = s.size();
    for(int i = 0; i < sz; i++){
        if(is_int(s[i])){
            nums[s[i] - '0']++;
        }
    }
    string ans;
    for(int i = 9; i >= 0; i--){
        string str = to_string(i);
        for(int j = 0; j < nums[i]; j++){
            ans += str;
        }
    }
    cout << ans << '\n';
    return 0;
}