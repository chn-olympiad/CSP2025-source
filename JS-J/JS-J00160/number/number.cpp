#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 100010;
vector<char> v;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0;i < len;i++){
        if('0' <= s[i] && s[i] <= '9') v.push_back(s[i]);
    }
    sort(v.begin(),v.end(),greater<int>());
    if(v[0] == '0') cout << 0 << endl;
    else{
        for(char c:v) cout << c;
        cout << endl;
    }
    return 0;
}
