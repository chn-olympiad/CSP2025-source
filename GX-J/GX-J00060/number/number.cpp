#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    cin >> s;
    string s1;
    for(int i=0; i<s.size(); i++){
        if(s[i]-'0' <= 9 and s[i]-'0' >= 0){
           s1.push_back(s[i]);
        }
    }
    sort(s1.begin(), s1.end());
    reverse(s1.begin(), s1.end());
    for(int i=0; i<s1.size(); i++){
        cout << s1[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
