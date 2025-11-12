#include <bits/stdc++.h>
using namespace std;

const int  maxn = 200005;
int        n, q;
string     s[maxn][2];
string     t1, t2;
string     tmp;
int        cnt, ans;

int main()
{
    freopen("replace.in",  "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> s[i][0] >> s[i][1];
    }
    for (int i = 0; i < q; i++){
        cin >> t1 >> t2;
        ans = 0;
        tmp = t1;
        // tmp2 = "";
        
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        for (int j = 0; j < n; j++){
            if (t1 == s[j][0] && t2 == s[j][1]){
                ans++;
                continue;
            }
            for (int k = 0; k < t1.size()-s[j][0].size(); k++){cnt = 0;
                for (int l = k; l <= k+s[j][0].size(); l++){
                    
                    if (t1[l] == s[j][0][l-k]){
                        cnt++;
                    }
                }
                if (cnt == s[j][0].size()){
                    for (int l = k; l < s[j][0].size(); l++){
                        tmp[l] = s[j][1][l-k];
                        if (tmp == t2){
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
        // cout << 0 << endl;
    }
    return 0;
}