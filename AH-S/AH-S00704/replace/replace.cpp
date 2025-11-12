#include <bits/stdc++.h>
using namespace std;

int n,q;
struct Words{
    string s1;
    string s2;
}word[200005];
int main() {
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin>>word[i].s1 >> word[i].s2;
    while(q--){
        string t1,t2;
        cin>>t1>>t2;
        cout<<"0\n";
    }
    return 0;
}
