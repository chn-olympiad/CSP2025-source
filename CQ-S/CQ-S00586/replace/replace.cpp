// Problem: replace (40tps)
// Check: [freopen] [long long] [O()] [Bigdata]
// by 1000ttank
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve() {
    int n,q; cin >> n >> q;
    map<int,int> mp;
    for (int i=1;i<=n;i++) {
    	string s1,s2;
        cin >> s1 >> s2;
        int t1=0,t2=0;
        for (int j=0;j<s1.size();j++) if (s1[j]=='b') t1=j;
        for (int j=0;j<s2.size();j++) if (s2[j]=='b') t2=j; 
        mp[t1-t2]++;
    }
    for (int i=1;i<=q;i++) {
        string s1,s2;
		cin >> s1 >> s2;
        int t1=0,t2=0;
        for (int j=0;j<s1.size();j++) if (s1[j]=='b') t1=j;
        for (int j=0;j<s2.size();j++) if (s2[j]=='b') t2=j; 
        cout << mp[t1-t2] << endl;
    }
}
int main() {
    #define CONTEST
    
    #ifdef CONTEST
    #ifndef LOCAL
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    #endif
    #endif

    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}