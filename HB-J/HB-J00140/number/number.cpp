#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
string s;
int num[1000005];
int i = 1;
int main(){
    freopen("number.in", 'r', stdin);
    freopen("number.out", 'w', stdout);
    cin >> s;
    for (int j = 0; j < s.size(); j ++){
        if ('0' <= s[j] && s[j] <= '9'){
            num[i] = s[j] - '0';
            i ++;
        }
    }
    sort(num + 1, num + i + 1);
    for (int j = i; j > 1; j --)
        cout << num[j];
    return 0;
}
