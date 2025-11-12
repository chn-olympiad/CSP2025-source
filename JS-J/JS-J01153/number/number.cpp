#include <bits/stdc++.h>
using namespace std;
int tong[20];
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++){
        if (str[i] == '0' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9'){
            tong[str[i] - '0']++;
        }
    }
    for (int i = 9; i >= 0; i--){
        while (tong[i] > 0){
            cout << i;
            tong[i]--;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
