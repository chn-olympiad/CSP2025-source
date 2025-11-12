#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    string n, m = "";
    cin >> n;
    for(int i = 0;i < (int)n.size();i++){
        if(n[i] >= '0' && n[i] <= '9'){
            m += n[i];
        }
    }sort(m.begin(), m.end(), greater<int>());
    cout << m;
    return 0;
}
