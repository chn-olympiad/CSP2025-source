#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
string s1[N], s2[N];
int n, q;
struct node{
    int start;
    int delta;
    int end;
} nodes[N];
bool special(){
    int nb = 0;
    for (int i = 0; i < n; i++){
        nb = 0;
        for (int j = 0; j < s1[i].length(); j++)
            if (s1[i][j] == 'b') nb++;
            else if (s1[i][j] != 'a') return false;
        if (nb != 1) return false;
    }
    // cout << 1234 << endl;
    for (int i = 0; i < n; i++){
        int a = s1[i].find("b"), b = s2[i].find("b");
        nodes[i].start = a;
        nodes[i].delta = b-a;
        nodes[i].end = s1[i].length() - b;
    }
    while (q--){
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()){
            cout << 0 << '\n';
            continue;
        }
        int a1 = t1.find("b"), a2 = t2.find("b");
        int ans = 0;
        int end = t1.length() - a2;
        for (int i = 0; i < n; i++){
            if (nodes[i].delta == a2-a1 &&
                a1 >= nodes[i].start &&
                end >= nodes[i].end) ans++;
        }
        cout << ans << '\n';
    }
    return true;
}
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> s1[i] >> s2[i];
    }
    if (n > 1000 && special()) return 0;
    while (q--){
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.length() != t2.length()){
            cout << 0 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++){
            unsigned int a = t1.find(s1[i]);
            if (a > t1.length()) continue;
            if (t1.replace(a, s1[i].length(), s2[i]) == t2) ans++;
            t1.replace(a, s1[i].length(), s1[i]);

        }
        cout << ans << '\n';
    }
    return 0;
}