#include<bits/stdc++.h>
using namespace std;
string s;
vector <int> v;
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(int i = 0;i < s.size();i++){
        int x = s[i] - '0';
        if(x >= 0 && x <= 9)
            v.push_back(x);
    }
    sort(v.begin(),v.end(),greater <int>());
    for(auto it : v)
        cout << it;
    cout << endl;
    return 0;
}