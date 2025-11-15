#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;
    string s[10004][3];

    cin >> n >> q;
    for(int i=1; i<=n; i++){
        cin >> s[i][1] >> s[i][2];
    }
    if(n <= 100 && q <= 100){
        while(q--){
            string t1, t2;
            cin >> t1 >> t2;
            if(t1.size() != t2.size()){
                cout << "0\n";
                break;
            }
            int ans = 0;
            for(int i=1; i<=n; i++){
                for(int j=0; t1.size() >= s[i][1].size() && j <= t1.size()-s[i][1].size(); j++){
                    if(s[i][1] != t1.substr(j, s[i][1].size())) continue;
                    string t3 = t1.substr(0, j) + s[i][2] + t1.substr(j+s[i][1].size(), t1.size()-j-s[i][1].size());
                    if(t3 == t2) ans++;
                }
            }
            cout << ans << '\n';
        }
    }else{
        map<char, vector<int>>mp;
        for(int i=1; i<=n; i++){
            mp[s[i][1][0]].push_back(i);
        }
        while(q--){
            string t1, t2;
            cin >> t1 >> t2;
            if(t1.size() != t2.size()){
                cout << "0\n";
                break;
            }
            int ans = 0;
            for(int i=0; i<t1.size(); i++){
                char c = t1[i];
                for(int j=0; j<mp[c].size(); j++){
                    int k = mp[c][j];
                    if(i + s[k][1].size() >= t1.size() && s[k][1] != t1.substr(i, s[k][1].size())) continue;
                    // printf("%d %d, %ld, %ld %ld\n", 0, i, s[k][2].size(), i+s[k][1].size(), t1.size()-i-s[k][1].size());
                    string t3 = t1.substr(0, i) + s[k][2] + t1.substr(i+s[k][1].size(), t1.size()-i-s[k][1].size());
                    if(t3 == t2) ans++;
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}