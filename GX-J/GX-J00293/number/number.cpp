#include <bits/stdc++.h>
using namespace std;
string a;
vector<int> gh;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> a;
    for (auto& d : a){
        if (d >= 'a' && d <= 'z'){
            continue;
        }
        else{
            gh.push_back(d - 48);
        }
    }
    int n = gh.size();
    int g[n];
    for (int i = 0;i <= n;i++){
        g[i] = gh[i];
    }
    sort(g,g+n);
    reverse(g,g+n);
    for (auto& s : g){
        cout << s;
    }
    cout << "\n";
    return 0;
}
