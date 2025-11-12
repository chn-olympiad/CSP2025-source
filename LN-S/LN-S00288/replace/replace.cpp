#include <bits/stdc++.h>
using namespace std;

namespace L1SkyL {
    void Main();
}

int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    L1SkyL::Main();
    return 0;
}

namespace L1SkyL{
    int n,q;
    pair <string,string> str[111];

    int pi[114];
    void KMP(string t,string s){
        t = " " + t;
        s = " " + s;
        int p = 0;
        int l = s.length(),m = t.length();
        p = 0;
        for (int i = 1;i <= l;++i){
            if (t[p + 1] == s[i]) ++p;
            else {
                while (p && t[p + 1] != s[i]) p = pi[p];
                if (t[p + 1] == s[i]) ++p;
            }
            if (p == m){
                
            }
        }
    }
    void Main(){
        cin >> n >> q;
        for (int i = 1;i <= n;++i){
            cin >> str[i].first >> str[i].second;
        }
        while (q--){
            if (n <= 100){
                
            }
        }
    }
}
