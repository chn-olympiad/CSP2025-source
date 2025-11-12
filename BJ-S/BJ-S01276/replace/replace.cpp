#include <bits/stdc++.h>
using namespace std;
string s[200010][2];
//map<string , string> mp;
int n , q;
int main(){
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    cin >> n >> q;
    for (int i = 0 ; i < n ; i ++){
        cin >> s[i][0] >> s[i][1];
        //mp[s[i][0]] = s[i][1];
    }
    for (int i = 0 ; i < q ; i ++){
        string sq[2];
        cin >> sq[0] >> sq[1];
        long long ans = 0;
        for (int j = 0 ; j < n ; j ++){
            int tmp1 = sq[0].find(s[j][0]) , tmp2 = sq[1].find(s[j][1]);
            if (tmp1 < sq[0].size() && tmp2 < sq[1].size()){
                string t1;
                t1 = sq[0].substr(0 , tmp1) + s[j][1] + sq[0].substr(tmp1 + s[j][0].size());
                //cout << tmp1 << " " << tmp2 << " ";
                //cout << sq[0].substr(0 , tmp1) << " " << s[j][1] << " " << sq[0].substr(tmp1 + s[j][0].size()) << " ";
                //cout << t1 << " " << sq[1] << "\n";
                if (t1 == sq[1]) ans ++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}