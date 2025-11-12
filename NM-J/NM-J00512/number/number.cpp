#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    vector<int> num;
    for(auto i : s){
        if(i-'0' >= 0 && i-'0' <= 9){
            num.push_back(i-'0');
        }
    }
    sort(num.begin(),num.end());
    for(int i = num.size()-1;i>=0;i--){
        cout << num[i];
    }
    return 0;
}
