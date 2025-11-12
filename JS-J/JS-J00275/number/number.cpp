#include <bits/stdc++.h>
using namespace std;
bool cmp(int x, int y){return x > y;}
string s;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> s;
    int l = s.length();
    vector <int> a;
    for(int i = 0; i < l; i++){
        if(s[i] >= '0' && s[i] <='9')a.push_back(s[i] - '0');
    }
    sort(a.begin(), a.end(), cmp);
    for(auto it : a){
        cout << it;
    }
    cout << endl;
    return 0;
}
