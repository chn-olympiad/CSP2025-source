#include <iostream>
using namespace std;

int a[12];
char s[1000005];

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] >= '0' && s[i] <= '9'){
            a[s[i] - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--){
        for (int j = 0; j < a[i]; j++){
            cout << i;
        }
    }
    return 0;
}
