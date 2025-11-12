#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    vector<int> a;
    for(int i = 0;i < s.length();i++){
        if(s[i]  >= '0' && s[i] <= '9'){
            a.push_back((int)(s[i] - '0'));
        }
    }
    sort(a.begin(), a.end());
    for(int i = a.size() - 1;i >= 0;i--){
        cout << a[i];
    }
    cout << endl;
    return 0;
}
