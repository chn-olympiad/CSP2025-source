#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 2e5 + 5;
const int B = 131;
int n , q;
string s1[N] , s2[N];
ull hash1[N] , hash2[N] , b[N] , h[N];
void Init() {
    memset(h , 0 , sizeof(h));
}
ull Hash(string s) {
    ull res = 0;
    for(int i = 0;i < s.size();i++) res = res * B + (s[i] - 'a' + 1);
    return res;
}
ull Query(int l , int r) {
    if(l > r) return 0;
    ull res = h[r] - h[l - 1] * b[r - l + 1];
    return res;
}
bool Cal(string t1 , string t2 , int k) {
    ull p = Hash(t2);
    // cout << t1.size() << endl;
    // cout << s1[k].size() << endl;
    // cout << t1.size() - s1[k].size() << endl;
    for(int i = 0;i <= int(t1.size()) - int(s1[k].size());i++) {
        // cout << i << endl;
        if(Query(i , i + int(s1[k].size()) - 1) != hash1[k]) continue;
        // cout << i << " is ok." << endl;
        ull nh = Query(0 , i - 1) * b[int(t1.size()) - i] + 
                 hash2[k] * b[int(t1.size()) - i - int(s1[k].size())] +
                 Query(i + int(s1[k].size()) , int(t1.size()) - 1);
    // cout << nh << endl;
    // cout << hash
    // cout << p << endl;
        if(nh == p) return 1;
    }
    return 0;
}
int main() {
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
    cin >> n >> q;
    // cout << "In" << endl;
    b[0] = 1;
    for(int i = 1;i <= 1e5;i++) b[i] = b[i - 1] * B;
    // cout << "Finish1!" << endl;
    for(int i = 1;i <= n;i++) {
        cin >> s1[i] >> s2[i];
        // cout << i << endl;
        hash1[i] = Hash(s1[i]);
        hash2[i] = Hash(s2[i]);
    }
    while(q--) {
        Init();
        string t1 , t2;
        cin >> t1 >> t2;
        // cout << "other!" << endl;
        if(t1.size() != t2.size()) {
            cout << 0 << endl;
            continue;
        }
        h[0] = t1[0] - 'a' + 1;
        for(int i = 1;i < t1.size();i++) {
            h[i] = h[i - 1] * B + (t1[i] - 'a' + 1);
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) 
        {
            // cout << i << ": " << ans << endl;
            ans += Cal(t1 , t2 , i);
        }
        cout << ans << endl;
    }
    return 0;
}