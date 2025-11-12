#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int n, q;
string s1[200005], s2[200005];
int len[200005], st[200005], en[200005];
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        cin >> s1[i] >> s2[i];
        for(int j = 0;j < s1[i].size();j++){
            if(s1[i][j] != s2[i][j]){
                st[i] = j;
                break;
            }
        }
        for(int j = s1[i].size()-1;j > 0;j--){
            if(s1[i][j] != s2[i][j]){
                en[i] = j;
                break;
            }
        }
        len[i] = en[i] - st[i] + 1;
    }
    for(int i = 1;i <= q;i++){
        string t1, t2;
        cin >> t1 >> t2;
        if(t1.size() != t2.size()){
            cout << 0 << endl;
            continue;
        }
        int st1, en1, ln1;
        for(int j = 0;j < t1.size();j++){
            if(t1[j] != t2[j]){
                st1 = j;
                break;
            }
        }
        for(int j = t1.size()-1;j >= 0;j--){
            if(t1[j] != t2[j]){
                en1 = j;
                break;
            }
        }
        ln1 = en1 - st1 + 1;
        int ans = 0;
        //cout << ln1 << " " << st1 << " " << en1 << endl;
        for(int j = 1;j <= n;j++){
            //cout << len[j] << " " << st[j] << " " << en[j] << endl;
            if(len[j] == ln1 && st[j] <= st1 && s1[j].size() - en[j] <= t1.size() - en1){
                int o = st[j];
                bool op = false;
                for(int k = st1;k <= en1;k++){
                    if(t1[k] != s1[j][o] || t2[k] != s2[j][o]){
                        op = true;
                        break;
                    }
                    o++;
                }
                //cout << 0 << endl;
                if(op == true) continue;
                //cout << 1 << endl;
                o = st1 - st[j];
                for(int k = 0;k < st[j];k++){
                    if(t1[o] != s1[j][k]){
                        op = true;
                        break;
                    }
                    o++;
                }
                if(op == true) continue;
                //cout << 2 << endl;
                o = en1;
                for(int k = en[j];k < s1[j].size();k++){
                    if(t1[o] != s1[j][k]){
                        op = true;
                        break;
                    }
                    o++;
                }
                if(op == true) continue;
                //cout << 3 << endl;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
