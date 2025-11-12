#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, maxl = 5e6 + 5;
string s[maxn][2], t[2], sta[maxn];
int n, q, ans;
int main(){
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    //printf("%d -- %d\n", n, q);
    if(n <= 100 && q <= 100){
        for(int i = 1; i <= n; i ++) cin >> s[i][0] >> s[i][1];
        //for(int i = 1; i <= n; i ++) sta[i] = s[i][0];
        for(int i = 1; i <= q; i ++){
            cin >> t[0] >> t[1];
            ans = 0;
            string tmp = t[0];
            int len = t[0].size();
            for(int j = 1; j <= n; j ++){
                //cout << s[j][0] << endl;
                for(int k = 0; k < len - s[j][0].size(); k ++){
                    bool flag = true;
                    for(int l = 0; l < s[j][0].size(); l ++){
                        if(tmp[k + l] != s[j][0][l]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag){
                            //printf("----\n");
                        for(int l = 0; l < s[j][0].size(); l ++) tmp[l + k] = s[j][0][l];
                    //cout << tmp << endl;
                    }
                }
                //cout << tmp << endl;
                bool flag = true;
                for(int k = 0; k < len; k ++) if(tmp[k] != t[1][k]) {
                    flag = false;
                    break;
                }
                if(flag) ans ++;
                //printf("%d --\n", ans);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
