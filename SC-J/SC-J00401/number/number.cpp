#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> a;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int sz = s.size();
    for(int i = 0;i < sz;i++){
        if(isdigit(s[i])){
            a.push_back(s[i] - '0');
        }
    }
    sort(a.begin(),a.end(),[](int x,int y){ return x > y; });
    for(int i = 0;i < (int)a.size();i++){
        cout << a[i];
    }
    return 0;
}