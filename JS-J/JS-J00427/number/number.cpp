#include <bits/stdc++.h>
using namespace std;
//number

char ch;
int p[10];

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    while (cin >> ch && ch != '\n'){
        if (ch >= '0' && ch <= '9'){
            p[ch - '0']++;
        }
    }
    for (int i = 9;i >= 0;i--){
        for (int j = 1;j <= p[i];j++){
            cout << (char)(i + '0');
        }
    }
    cout << endl;
    return 0;
}
