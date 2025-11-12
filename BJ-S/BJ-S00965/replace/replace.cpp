#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200005;
string s1[MAXN], s2[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++){
        cin >> s1[i] >> s2[i];
    }
    while(q --){
        string t1, t2;
        int ans = 0;
        cin >> t1 >> t2;
        for(int i = 1; i <= n; i ++){
            string tmp = "";
            int sta = t1.find(s1[i]);
            if(sta != -1){
                for(int j = 0; j < t1.size(); j ++){
                    if(j >= sta && j < sta + s1[i].size())tmp += s2[i][j - sta];
                    else tmp += t1[j];
                }
                if(tmp == t2)ans ++;
            }
        }
        cout << ans << "\n";
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
*/