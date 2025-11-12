//long long memory time
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 200007;
long long n[N], cnt;
vector<int> vec;
string s;
bool cmp(int a, int b){
    return a > b;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= '0' && s[i] <= '9'){
            n[i] = s[i] - '0';
            vec.push_back(n[i]);
            cnt++;
        }
    }
    sort(vec.begin(), vec.end(), cmp);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    return 0;
}
