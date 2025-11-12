#include <bits/stdc++.h>
using namespace std;

string s1[200005], s2[200005];
int c[200005];
int main(){
    // string s="zz", p="s";
    // cout << s.find(p);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    string t1, t2;
    cin >> n >> q;
    for(int i=1;i <= n;i++){
        cin >> s1[i] >> s2[i];
        // if(s1[i] == "s" && s2[i] == "z") cout << "ok";
        for(int j=0;j < s1[i].size();j++){
            if(s1[i][j] != s2[i][j]) c[i]++;
        }
    }
    for(int i=1;i <= q;i++){
        cin >> t1 >> t2;
        int ch=0, cnt=0;
        for(int j=0;j < t1.size();j++){
            if(t1[j] != t2[j]) ch++;
        }
        for(int j=1;j <= n;j++){
            // if(i == 3182 && t1.find(s1[j]) != string::npos && t2.find(s2[j]) != string::npos && t1.find(s1[j]) == t2.find(s2[j])) cout << c[j] << "\n";
            if(c[j] == ch && t1.find(s1[j]) != string::npos && t2.substr(t1.find(s1[j]), s1[j].size()) == s2[j]){
                cnt++;
            }
            else if(c[j] == ch && t2.find(s2[j]) != string::npos && t1.substr(t2.find(s2[j]), s2[j].size()) == s1[j]){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}