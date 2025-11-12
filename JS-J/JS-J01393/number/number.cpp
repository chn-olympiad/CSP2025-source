#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
string s;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        if('0' <= s[i] && s[i] <= '9')
            v.push_back(s[i]-'0');
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    if(v[0] == 0) cout << 0 << endl, exit(0);
    for(int i = 0; i < v.size(); i++)
        cout << v[i];
    cout << endl;
    return 0;
}
