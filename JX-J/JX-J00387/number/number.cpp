#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string n;
    vector<char> m;
    cin >> n;
    for(int i = 0;i < n.size();i++){
        if(n[i] >= '0' and n[i] <= '9'){
            m.push_back(n[i]);
        }
    }
    sort(m.begin(),m.end());
    for(int i = m.size()-1;i >= 0;i--){
        cout << m[i];
    }
    return 0;
}
