#include <bits/stdc++.h>
using namespace std;

string s;
vector<char> v;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    cin >> s;
    int len_of_s = s.size();
    for (int i = 0; i < len_of_s; i++){
        if ('0' <= s[i] && s[i] <= '9'){
            v.push_back(s[i]);
        }
    }

    sort(v.begin(), v.end(), greater<char>());

    int size_of_v = v.size();
    for (int i = 0; i < size_of_v; i++){
        printf("%c", v[i]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
