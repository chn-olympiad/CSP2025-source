#include <bits/stdc++.h>
using namespace std;
string sz[200010][3];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    int n, k;
    cin >> n>> k;
    for(int i=1;i<=n;i++){
        cin >> sz[i][1] >> sz[i][2];
    }
    while(k--){
        string f, t;
        cin >> f >> t;
        if(f.size() != t.size()){
            puts("0");
            continue;
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            int ix = f.find(sz[i][1]);
            if(ix != -1){
                if(f.substr(0, ix)==t.substr(0, ix)){
                    if(sz[i][2] == t.substr(ix, sz[i][2].size())){
                        if(ix+sz[i][1].size() >= f.size() || f.substr(ix+sz[i][1].size()) == t.substr(ix+sz[i][1].size())){
                            ans++;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/