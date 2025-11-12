#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
string x;
vector<char> a;
int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x;
    for (ll i = 0; i < x.size(); i++){
        if (x[i] >= '0' && x[i] <= '9'){
            a.push_back(x[i]);
        }
    }
    sort(a.begin(), a.end(), greater<char>());
    for (ll i = 0; i < a.size(); i++){
        cout << a[i];
    }
    return 0;
}
