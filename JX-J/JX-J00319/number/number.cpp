#include<bits/stdc++.h>
using namespace std;

string num;
string n;
bool cmp(char a, char b){
    return a > b;
}
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> n;
    for(int i = 0;i < (int)n.size();i++){
        if(n[i] >= '0' && n[i] <= '9'){
            num.push_back(n[i]);
        }
    }
    sort(num.begin(), num.end(), cmp);
    cout << num;
    return 0;
}
