#include <iostream>
#include <vector>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;

    vector<int> a(10);

    for (int i=0; i < s.size(); ++i){
        if ('0' <= s[i] && s[i] <= '9'){ // is number
            a[s[i]-'0']++;
        }
    }

    /*
    for (int i=0; i < 10; ++i){ //debug 1
        cout << i << ' ' << a[i] << endl;
    }
    */

    for (int i=9; i >= 0; --i){
        for (int j=0; j < a[i]; ++j){
            cout << i;
        }
    }

    return 0;
}
