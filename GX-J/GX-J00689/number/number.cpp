#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string s;
    cin >> s;
    int num_max = 0;
    for (int i=0; i<s.size(); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            s[i] = 0;
        }
        cout << s[i] << endl;
    }
    s = stoi(s);
    for (int i=0; i<s.size(); i++){
       for (int j=0; j<s.size(); j++){
            if (s[i] > s[j]){
                swap(s[i], s[j]);
            }
       }
    }
    for (int i=0; i<s.length(); i++){
        if (s[i] == 0){
            num_max = num_max*10 +s[i];
        }
    }
    if (num_max == 0){
        num_max = stoi(s);
    }
    cout << num_max << endl;




    fclose(stdin);
    fclose(stdout);
    return 0;
}
