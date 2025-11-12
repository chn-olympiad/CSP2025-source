#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    char a;
    cin >> s;
    int n = s.size();
    int number[n + 5];
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if(s[i] >= 48 && s[i] <= 58){
            number[cnt] = int(s[i]) - 48;
            cnt += 1;
        }
    } sort(number, number + cnt - 1, greater<int>());
    for(int i = 1; i <= cnt - 1; i++){
        cout << number[i];
    }
    return 0;
}
