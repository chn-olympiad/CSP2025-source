#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    int num[15] = {0};

    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            num[int(s[i] - '0')]++;
        }
    }

    for (int i = 9; i >= 0; i--){
        for (int j = 1; j <= num[i]; j++){
            cout << i;
        }
    }

    return 0;
}
