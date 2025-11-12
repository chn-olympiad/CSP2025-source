#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    vector <int> v;
    cin >> s;
    for (int i = 0;i < s.length();i++){
        if (s[i] >= '0' && s[i] <= '9'){
            v.push_back(s[i] - '0');
        }
    }
    for (int i = 1;i <= v.size();i++){
        for (int j = 0;j < v.size() - i;j++){
            if (v[j] < v[j + 1]){
                swap(v[j],v[j + 1]);
            }
        }
    }
    for (int i = 0;i < v.size();i++){
        cout << v[i];
    }
    return 0;
}
